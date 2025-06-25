bits    64
default rel

%include "mandelbrot.inc"

MANDELBROT_BUFFER_WIDTH  equ 1920
MANDELBROT_BUFFER_HEIGHT equ 1080
MANDELBROT_BUFFER_LEN    equ (MANDELBROT_BUFFER_WIDTH * MANDELBROT_BUFFER_HEIGHT)

section .rodata

string(static, debug_fmt, "%g, {%g, %g}", 0xa, 0)

var(static, double_t, one_d, 1.0)

var(static, double_t, neg_d, 0x8000_0000_0000_0000)

var(static, double_t, inf_d, 100.0)
var(static, double_t, one_over_max_iter_d, 0.01)
var(static, double_t, uint8max_d, 255.0)

var(static, float_t, zoom_factor_f, 0.97)
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

var(static,  double_t,  one_over_width_d, 0.0025)
var(static,  double_t,  one_over_height_d, 0.0025)

var(static, double_t, world_size_d, 4.0)

var(static, double_t, view_scale_x_d, 0.01)
var(static, double_t, view_scale_y_d, 0.01)

var(static, double_t, view_offset_x_d, 0.0)
var(static, double_t, view_offset_y_d, 0.0)

section .bss

res_array(static, color_t, mandelbrot_buffer, MANDELBROT_BUFFER_LEN)

mandelbrot_buffer_tex:
static  mandelbrot_buffer_tex: data
	resb sizeof(Texture)

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
	mov  uint64_p [width_u], rax

	movq     xmm0,                        double_p [one_d]
	cvtsi2sd xmm1,                        rax
	divsd    xmm0,                        xmm1
	movq     double_p [one_over_width_d], xmm0

	shr rax,                     1
	mov uint64_p [half_width_u], rax

	call GetScreenHeight
	mov  uint64_p [height_u], rax

	movq     xmm0,                         double_p [one_d]
	cvtsi2sd xmm1,                         rax
	divsd    xmm0,                         xmm1
	movq     double_p [one_over_height_d], xmm0

	shr rax,                      1
	mov uint64_p [half_height_u], rax

	add rsp, 8
	ret

func(static, handle_zoom)
	sub rsp, 8

	call  GetMouseWheelMove
	xorps xmm1, xmm1

	ucomiss xmm0, xmm1
	je      .skip_zoom
		xorps    xmm1,                    xmm1
		mulss    xmm0,                    float_p [zoom_factor_f]
		cvtss2sd xmm0,                    xmm0
		movq     xmm1,                    double_p [world_size_d]
		mulsd    xmm1,                    xmm0
		movq     xmm0,                    double_p [neg_d]
		orpd     xmm1,                    xmm0
		xorpd    xmm1,                    xmm0
		movq     double_p [world_size_d], xmm1
	.skip_zoom:

	movq xmm1, double_p [world_size_d]

	movq  xmm0,                      double_p [one_over_width_d]
	mulsd xmm0,                      xmm1
	movq  double_p [view_scale_x_d], xmm0

	movq  xmm0,                      double_p [one_over_height_d]
	mulsd xmm0,                      xmm1
	movq  double_p [view_scale_y_d], xmm0

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

func(static, update_buffer)
	sub rsp, 8

	push r12
	push r13
	push r14
	push r15

	mov r14, uint64_p [height_u]
	mov r15, uint64_p [width_u]

	xor r12, r12
	.loop_y:
		xor r13, r13
		.loop_x:
			mov  rdi, r13
			mov  rsi, r12
			call pixel_to_world

			movq xmm2, double_p [inf_d]
			mov  rdi,  MAX_ITER
			call mandelbrot

			cmp      rax,  MAX_ITER
			jne      .skip_zero
			xor      rax,  rax
			.skip_zero:
			cvtsi2sd xmm0, rax

			mulsd    xmm0, double_p [one_over_max_iter_d]
			mulsd    xmm0, double_p [uint8max_d]
			cvtsd2si rax,  xmm0
			mov      rdx,  0x01_01_01_01
			mul      edx
			mov      edx,  eax
			or       edx,  A_MASK
			mov      esi,  edx

			mov rax,           MANDELBROT_BUFFER_WIDTH
			mul r12
			add rax,           r13
			shl rax,           2
			lea rdi,           [mandelbrot_buffer]
			add rdi,           rax
			mov color_p [rdi], esi

			; mov  rdi, r13
			; mov  rsi, r12
			; call DrawPixel

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
	
	add rsp, 8
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
