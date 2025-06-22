%ifndef SETUP_INC
%define SETUP_INC

%include "raylib.inc"
%include "std.inc"

SCREEN_WIDTH  equ 400
SCREEN_HEIGHT equ 400

; void setup_program(uint64_t argc, char** argv);
extern setup_program

%endif ; SETUP_INC
