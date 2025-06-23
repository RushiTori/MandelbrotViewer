bits    64
default rel

%include "main.inc"

MAX_ITER equ 200

section      .rodata

var(static, float_t, mouse_radius, 50.0e0)

var(static, double_t, neg_d, 0x8000_0000_0000_0000)
var(static, double_t, x_step_d, 0.0025)
var(static, double_t, y_step_d, 0.0025)
var(static, double_t, inf_d, 1.0e11)
var(static, double_t, view_size_d, 4.0)
var(static, double_t, view_correction_d, 2.0)
var(static, double_t, one_over_max_iter_d, 0.005)
var(static, double_t, uint8max_d, 255.0)

section      .text

; uint64_t get_mandelbrot_d(double a, double b, double inf, uint64_t iter);
func(static, get_mandelbrot_d)
	cmp rdi, 0
	je  .end

	movsd xmm3, xmm0
	movsd xmm4, xmm1

	mov      rax,  2
	cvtsi2sd xmm5, rax
	xor      rax,  rax

	.loop_:
		movsd xmm6, xmm3
		mulsd xmm6, xmm4
		mulsd xmm6, xmm5

		mulsd xmm3, xmm3
		mulsd xmm4, xmm4

		subsd xmm3, xmm4
		movsd xmm4, xmm6

		addsd xmm3, xmm0
		addsd xmm4, xmm1

		movsd xmm6, xmm3
		addsd xmm6, xmm4

		movq  xmm7, double_p [neg_d]
		xorps xmm7, xmm6
		maxsd xmm6, xmm7

		comisd xmm6, xmm2
		jae    .end

		inc rax
		cmp rax, rdi
		jl  .loop_
	
	.end:
	ret

func(static, update_game)
	;sub rsp, 8
	
	; Update code goes here

	;add rsp, 8
	ret

func(static, render_game)
	sub rsp, 8

	push r12
	push r13

	call BeginDrawing

	mov  rdi, COLOR_BLACK
	call ClearBackground

	; Render code goes here

	xor r12, r12
	.loop_y:
		xor r13, r13
		.loop_x:
			cvtsi2sd xmm0, r13
			mulsd    xmm0, double_p [x_step_d]
			mulsd    xmm0, double_p [view_size_d]
			subsd    xmm0, double_p [view_correction_d]

			cvtsi2sd xmm1, r12
			mulsd    xmm1, double_p [y_step_d]
			mulsd    xmm1, double_p [view_size_d]
			subsd    xmm1, double_p [view_correction_d]

			movq xmm2, double_p [inf_d]
			mov  rdi,  MAX_ITER
			call get_mandelbrot_d

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

			or   edx, A_MASK
			mov  rdi, r13
			mov  rsi, r12
			call DrawPixel

			inc r13
			cmp r13, SCREEN_WIDTH
			jne .loop_x
		inc r12
		cmp r12, SCREEN_HEIGHT
		jne .loop_y

	xor  rdi, rdi
	xor  rsi, rsi
	call DrawFPS

	call EndDrawing

	pop r13
	pop r12
	
	add rsp, 8
	ret

func(global, _start)
	mov  rdi, uint64_p [rsp]           ; argc
	lea  rsi, [rsp + sizeof(uint64_s)] ; argv
	call setup_program

	.game_loop:
		call WindowShouldClose
		cmp  al, true
		je   .end_game_loop

		call update_game
		call render_game

		jmp .game_loop
	.end_game_loop:

	call CloseWindow

	mov rax, SYSCALL_EXIT
	mov rdi, EXIT_SUCCESS
	syscall
