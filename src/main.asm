bits    64
default rel

%include "main.inc"

MAX_ITER equ 100

section      .rodata

var(static, float_t, mouse_radius, 50.0e0)
var(static, float_t, neg_f, 0x80_00_00_00)

var(static, float_t, x_step_f, 0.0025)
var(static, float_t, y_step_f, 0.0025)
var(static, float_t, inf_f, 32.0)
var(static, float_t, view_size_f, 4.0)
var(static, float_t, view_correction_f, 2.0)
var(static, float_t, one_over_max_iter_f, 0.01)
var(static, float_t, uint8max_f, 255.0)

section      .bss

res(static,  vector2_t, mouse_pos_v)

section      .text

; uint64_t get_mandelbrot(float a, float b, float inf, uint64_t iter);
func(static, get_mandelbrot)
	cmp rdi, 0
	je  .end

	movss xmm3, xmm0
	movss xmm4, xmm1

	mov      rax,  2
	cvtsi2ss xmm5, rax
	xor      rax,  rax

	.loop_:
		movss xmm6, xmm3
		mulss xmm6, xmm4
		mulss xmm6, xmm5

		mulss xmm3, xmm3
		mulss xmm4, xmm4

		subss xmm3, xmm4
		movss xmm4, xmm6

		addss xmm3, xmm0
		addss xmm4, xmm1

		movss xmm6, xmm3
		addss xmm6, xmm4

		movd  xmm7, float_p [neg_f]
		xorps xmm7, xmm6
		maxss xmm6, xmm7

		comiss xmm6, xmm2
		jae    .end

		inc rax
		cmp rax, rdi
		jle .loop_
	
	.end:
	ret

func(static, update_game)
	sub rsp, 8
	
	; Update code goes here
	call GetMousePosition
	movq vector2_p [mouse_pos_v], xmm0

	add rsp, 8
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
			cvtsi2ss xmm0, r13
			mulss    xmm0, float_p [x_step_f]
			mulss    xmm0, float_p [view_size_f]
			subss    xmm0, float_p [view_correction_f]

			cvtsi2ss xmm1, r12
			mulss    xmm1, float_p [y_step_f]
			mulss    xmm1, float_p [view_size_f]
			subss    xmm1, float_p [view_correction_f]

			movd xmm2, float_p [inf_f]

			mov rdi, MAX_ITER

			call get_mandelbrot

			cvtsi2ss xmm0, rax
			mulss    xmm0, float_p [one_over_max_iter_f]
			mulss    xmm0, float_p [uint8max_f]
			cvtss2si rax,  xmm0

			mov rdx, 0x01_01_01_01
			mul edx
			mov edx, eax
			or  edx, A_MASK

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
