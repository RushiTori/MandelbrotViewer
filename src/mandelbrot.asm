bits    64
default rel

%include "mandelbrot.inc"

extern  pow

MANDELBROT_BUFFER_WIDTH  equ 1920
MANDELBROT_BUFFER_HEIGHT equ 1080
MANDELBROT_BUFFER_LEN    equ (MANDELBROT_BUFFER_WIDTH * MANDELBROT_BUFFER_HEIGHT)

section .rodata

string(static, debug_fmt, "%g, {%g, %g}", 0xa, 0)

var(static, double_t, one_d, 1.0)

var(static, double_t, neg_d, 0x8000_0000_0000_0000)

var(static, double_t, inf_d, 100.0)
var(static, double_t, one_over_max_iter_d, 0.01)

var(static, double_t, zoom_factor_d, 0.95)
var(static, uint64_t, pan_speed_x_u, 4)
var(static, uint64_t, pan_speed_y_u, 4)

mandelbrot_buffer_img:
static  mandelbrot_buffer_img: data
	istruc Image
		at .data,    dq mandelbrot_buffer
		at .width,   dd MANDELBROT_BUFFER_WIDTH
		at .height,  dd MANDELBROT_BUFFER_HEIGHT
		at .mipmaps, dd 1
		at .format,  dd PIXELFORMAT_UNCOMPRESSED_R8G8B8A8
	iend

section .data

var(static,  uint64_t, width_u, 400)
var(static,  uint64_t, height_u, 400)

var(static,  uint64_t, half_width_u, 200)
var(static,  uint64_t, half_height_u, 200)

var(static, double_t, view_scale_x_d, 0.01)
var(static, double_t, view_scale_y_d, 0.01)

var(static, double_t, view_offset_x_d, 0.0)
var(static, double_t, view_offset_y_d, 0.0)

var(static, pointer_t, current_theme_callback, theme_gray_scale)

section .bss

res_array(static, color_t, mandelbrot_buffer, MANDELBROT_BUFFER_LEN)

mandelbrot_buffer_tex:
static  mandelbrot_buffer_tex: data
	resb sizeof(Texture)

res_array(static, pthread_t, threads, MAX_THREAD_COUNT)

res(static,  uint64_t, thread_pix_height)

res_array(static, uint64_t, thread_starts, MAX_THREAD_COUNT)

section      .text

; Initializes some states for the mandelbrot computation
; void init_mandelbrot(void);
func(global, init_mandelbrot)
	sub    rsp,         8 + 32
	mov    rax,         qword [mandelbrot_buffer_img]
	movups xmm0,        [mandelbrot_buffer_img + 8]
	mov    qword [rsp], rax
	movups [rsp + 8],   xmm0
	lea    rdi,         [mandelbrot_buffer_tex]
	call   LoadTextureFromImage
	add    rsp,         8 + 32
	ret

; Frees the states allocated by init_mandelbrot
; void free_mandelbrot(void);
func(global, free_mandelbrot)
	sub rsp, 24

	mov    eax,         dword [mandelbrot_buffer_tex]
	movups xmm0,        [mandelbrot_buffer_tex + 4]
	mov    dword [rsp], eax
	movups [rsp + 4],   xmm0
	call   UnloadTexture

	add rsp, 24
	ret

; Sets the current function used to compute the color of the mandelbrot (default: theme_gray_scale)
;     double: [0...1] percentage of the iteration done over MAX_ITER before reaching infinity
;     bool: shot-hand for (double == 1.0), tells if the current position did NOT reach infinity in MAX_ITER iterations
; void set_mandelbrot_theme_callback(Color (*f)(double, bool))
func(global, set_mandelbrot_theme_callback)
	mov pointer_p [current_theme_callback], rdi
	ret

; typedef struct {double x, y} VecD2;
; VecD2 pixel_to_world(uint64_t x, uint64_t y);
func(static, pixel_to_world)
	sub      rdi,  uint64_p [half_width_u]
	cvtsi2sd xmm0, rdi
	mulsd    xmm0, double_p [view_scale_x_d]
	addsd    xmm0, double_p [view_offset_x_d]

	sub      rsi,  uint64_p [half_height_u]
	cvtsi2sd xmm1, rsi
	mulsd    xmm1, double_p [view_scale_y_d]
	addsd    xmm1, double_p [view_offset_y_d]
	ret

; uint64_t mandelbrot(double a, double b, double inf, uint64_t iter);
func(static, mandelbrot)
	cmp rdi, 0
	je  .end

	vshufps xmm0, xmm0, xmm1, 0b01_00_01_00
	movaps xmm3, xmm0

	mov      rax,  2
	cvtsi2sd xmm1, rax
	xor      rax,  rax

	.loop_:
		vshufps xmm4, xmm3, xmm3, 0b11_10
		mulsd xmm4, xmm3
		mulpd xmm3, xmm3
		vshufps xmm5, xmm3, xmm3, 0b11_10
		subsd xmm3, xmm5
		mulsd xmm4, xmm1
		vshufps xmm3, xmm3, xmm4, 0b01_00_01_00
		addpd xmm3, xmm0
		vshufps xmm4, xmm3, xmm3, 0b01_00_11_10
		addsd xmm3, xmm4

		xorps  xmm5, xmm5
		movq   xmm5, double_p [neg_d]
		xorpd  xmm5, xmm3
		maxsd  xmm5, xmm3
		comisd xmm5, xmm2
		jae    .end

		vshufps xmm3, xmm4, xmm3, 0b11_10_11_10

		inc rax
		cmp rax, rdi
		jl  .loop_

	.end:
	ret

func(static, update_screen_sizes)
	sub rsp, 8

	call GetScreenWidth
	mov  uint64_p [width_u],      rax
	shr  rax,                     1
	mov  uint64_p [half_width_u], rax

	call GetScreenHeight
	mov  uint64_p [height_u],      rax
	shr  rax,                      1
	mov  uint64_p [half_height_u], rax

	add rsp, 8
	ret

func(static, handle_zoom)
	sub rsp, 8

	call     GetMouseWheelMove
	cvtss2sd xmm1, xmm0
	movq     xmm0, double_p [zoom_factor_d]
	call     pow
	movsd    xmm1, xmm0
	
	mulsd xmm0,                      double_p [view_scale_x_d]
	movq  double_p [view_scale_x_d], xmm0
	mulsd xmm1,                      double_p [view_scale_y_d]
	movq  double_p [view_scale_y_d], xmm1

	add rsp, 8
	ret

func(static, handle_pan)
	sub rsp, 8

	mov  rdi, MOUSE_BUTTON_LEFT
	call IsMouseButtonDown
	cmp  al,  false
	je   .skip_pan

	call     GetMouseDelta
	movss    xmm1, xmm0
	shufps xmm0, xmm0, 1
	cvtss2sd xmm0, xmm0
	cvtss2sd xmm1, xmm1

	mulsd xmm1,                       double_p [view_scale_x_d]
	movq  xmm2,                       double_p [view_offset_x_d]
	subsd xmm2,                       xmm1
	movq  double_p [view_offset_x_d], xmm2

	mulsd xmm0,                       double_p [view_scale_y_d]
	movq  xmm2,                       double_p [view_offset_y_d]
	subsd xmm2,                       xmm0
	movq  double_p [view_offset_y_d], xmm2

	.skip_pan:

	add rsp, 8
	ret

; void thread_work(uint64_t* start_y)
func(static, thread_work)
	push rbx
	push r12
	push r13
	push r14
	push r15

	mov rbx, pointer_p [current_theme_callback]

	;mov r14, uint64_p [height_u]
	mov r15, uint64_p [width_u]

	mov r12, uint64_p [rdi]
	mov r14, uint64_p [thread_pix_height]
	add r14, r12
	.loop_y:
		xor r13, r13
		.loop_x:
			mov  rdi, r13
			mov  rsi, r12
			call pixel_to_world

			movq xmm2, double_p [inf_d]
			mov  rdi,  MAX_ITER
			call mandelbrot

			mov dil, false
			cmp rax, MAX_ITER
			jne .skip_far_from_inf
			mov dil, true
			.skip_far_from_inf:

			cvtsi2sd xmm0, rax
			mulsd    xmm0, double_p [one_over_max_iter_d]

			call rbx
			mov  esi, eax

			mov rax, MANDELBROT_BUFFER_WIDTH
			mul r12
			add rax, r13
			shl rax, 2

			lea rdi,           [mandelbrot_buffer]
			add rdi,           rax
			mov color_p [rdi], esi

			inc r13
			cmp r13, r15
			jne .loop_x
		inc r12
		cmp r12, r14
		jne .loop_y

	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
	ret

func(static, update_buffer)
	xor  rdx, rdx
	mov  rax, uint64_p [height_u]
	mov  rcx, MAX_THREAD_COUNT
	idiv rcx
	cmp  rdx, 0
	je   .skip_ceil
		inc rax
	.skip_ceil:

	mov uint64_p [thread_pix_height], rax
	
	lea rdi, [thread_starts]
	xor rsi, rsi
	.setup_thread_offsets:
		mov  uint64_p [rdi], rsi
		add  rdi,            sizeof(uint64_s)
		add  rsi,            rax
		loop .setup_thread_offsets

	push r12

	xor r12, r12
	.create_threads:
		mov rax, r12
		shl rax, 3
		
		lea rdi, [threads]
		add rdi, rax

		xor rsi, rsi

		lea rdx, [thread_work]
		
		lea rcx, [thread_starts]
		add rcx, rax

		call pthread_create

		inc r12
		cmp r12, MAX_THREAD_COUNT
		jne .create_threads

	xor r12, r12
	.join_threads:
		mov rax, r12
		shl rax, 3
		
		lea rdi, [threads]
		add rdi, rax
		mov rdi, pthread_p [rdi]

		xor rsi, rsi

		lea rdx, [thread_work]
		
		lea rcx, [thread_starts]
		add rcx, rax

		call pthread_join

		inc r12
		cmp r12, MAX_THREAD_COUNT
		jne .join_threads

	pop r12
	ret

; Updates the states of Mandelbrot (zoom, pan, etc.)
; void update_mandelbrot(void);
func(global, update_mandelbrot)
	sub rsp, 24

	call update_screen_sizes
	call handle_zoom
	call handle_pan
	call update_buffer

	mov    eax,         dword [mandelbrot_buffer_tex]
	movups xmm0,        [mandelbrot_buffer_tex + 4]
	mov    dword [rsp], eax
	movups [rsp + 4],   xmm0

	lea  rdi, [mandelbrot_buffer]
	call UpdateTexture

	add rsp, 24
	ret

; Renders the Mandelbrot Set
; void render_mandelbrot(void);
func(global, render_mandelbrot)
	sub rsp, 24

	mov    eax,         dword [mandelbrot_buffer_tex]
	movups xmm0,        [mandelbrot_buffer_tex + 4]
	mov    dword [rsp], eax
	movups [rsp + 4],   xmm0

	xor rdi, rdi
	xor rsi, rsi
	mov rdx, COLOR_WHITE

	call DrawTexture

	add rsp, 24
	ret
