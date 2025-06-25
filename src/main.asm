bits    64
default rel

%include "main.inc"

section .text

%macro try_change_theme_base 2
	mov  rdi, %1
	call IsKeyPressed
	cmp  al,  false
	je   %%skip_theme
		mov  rdi, %2
		call set_mandelbrot_theme_callback
	%%skip_theme:
%endmacro

%define try_change_theme(key, theme_callback) try_change_theme_base key, theme_callback

func(static, update_game)
	sub rsp, 8

	try_change_theme(KEY_SPACE, theme_gray_scale)
	try_change_theme(KEY_KP_0,  theme_hue_full)
	try_change_theme(KEY_KP_1,  theme_hue_red)
	try_change_theme(KEY_KP_2,  theme_hue_green)
	try_change_theme(KEY_KP_3,  theme_hue_blue)
	
	add rsp, 8
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

	call init_mandelbrot

	.game_loop:
		call WindowShouldClose
		cmp  al, true
		je   .end_game_loop

		call update_game
		call render_game

		jmp .game_loop
	.end_game_loop:

	call free_mandelbrot
	call CloseWindow

	mov rax, SYSCALL_EXIT
	mov rdi, EXIT_SUCCESS
	syscall
