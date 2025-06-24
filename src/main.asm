bits         64
default      rel

%include "main.inc"

section      .text

func(static, update_game)
	jmp update_mandelbrot

func(static, render_game)
	sub rsp, 8

	call BeginDrawing

	mov  rdi, COLOR_BLACK
	call ClearBackground

	; Render code goes here

	call render_mandelbrot

	xor  rdi, rdi
	xor  rsi, rsi
	call DrawFPS

	call EndDrawing
	
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
