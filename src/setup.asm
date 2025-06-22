bits         64
default      rel

%include "setup.inc"

section      .rodata

string(static, title_str, "ASM Raylib - Mandelbrot Set !", 0)

section      .text

; void handle_args(uint64_t argc, char** argv);
func(static, handle_args)
	ret

; void setup_raylib(void);
func(static, setup_raylib)
	sub rsp, 8

	mov  rdi, LOG_WARNING
	call SetTraceLogLevel

	mov  rdi, FLAG_WINDOW_RESIZABLE
	call SetConfigFlags

	mov  rdi, 60
	call SetTargetFPS

	mov  rdi, SCREEN_WIDTH
	mov  rsi, SCREEN_HEIGHT
	lea  rdx, [title_str]
	call InitWindow

	add rsp, 8
	ret

; void setup_program(uint64_t argc, char** argv);
func(global, setup_program)
	sub rsp, 8

	call handle_args

	call setup_raylib

	add rsp, 8
	ret
