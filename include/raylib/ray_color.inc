%ifndef RAY_COLOR_INC
%define RAY_COLOR_INC

R_MASK   equ 0x00_00_00_FF
R_LSHIFT equ 0

G_MASK   equ 0x00_00_FF_00
G_LSHIFT equ 8

B_MASK   equ 0x00_FF_00_00
B_LSHIFT equ 16

A_MASK   equ 0xFF_00_00_00
A_LSHIFT equ 24

%define color(r, g, b, a) ((r & 0xFF) << R_LSHIFT) + ((g & 0xFF) << G_LSHIFT) + ((b & 0xFF) << B_LSHIFT) + ((a & 0xFF) << A_LSHIFT)
    
; Custom raylib color palette for amazing visuals on WHITE background
; https://www.raylib.com/cheatsheet/cheatsheet.html
	COLOR_LIGHTGRAY  equ color(200, 200, 200, 255) ; Light Gray
	COLOR_GRAY       equ color(130, 130, 130, 255) ; Gray
	COLOR_DARKGRAY   equ color(80, 80, 80, 255)    ; Dark Gray
	COLOR_YELLOW     equ color(253, 249, 0, 255)   ; Yellow
	COLOR_GOLD       equ color(255, 203, 0, 255)   ; Gold
	COLOR_ORANGE     equ color(255, 161, 0, 255)   ; Orange
	COLOR_PINK       equ color(255, 109, 194, 255) ; Pink
	COLOR_RED        equ color(230, 41, 55, 255)   ; Red
	COLOR_MAROON     equ color(190, 33, 55, 255)   ; Maroon
	COLOR_GREEN      equ color(0, 228, 48, 255)    ; Green
	COLOR_LIME       equ color(0, 158, 47, 255)    ; Lime
	COLOR_DARKGREEN  equ color(0, 117, 44, 255)    ; Dark Green
	COLOR_SKYBLUE    equ color(102, 191, 255, 255) ; Sky Blue
	COLOR_BLUE       equ color(0, 121, 241, 255)   ; Blue
	COLOR_DARKBLUE   equ color(0, 82, 172, 255)    ; Dark Blue
	COLOR_PURPLE     equ color(200, 122, 255, 255) ; Purple
	COLOR_VIOLET     equ color(135, 60, 190, 255)  ; Violet
	COLOR_DARKPURPLE equ color(112, 31, 126, 255)  ; Dark Purple
	COLOR_BEIGE      equ color(211, 176, 131, 255) ; Beige
	COLOR_BROWN      equ color(127, 106, 79, 255)  ; Brown
	COLOR_DARKBROWN  equ color(76, 63, 47, 255)    ; Dark Brown
	COLOR_WHITE      equ color(255, 255, 255, 255) ; White
	COLOR_BLACK      equ color(0, 0, 0, 255)       ; Black
	COLOR_BLANK      equ color(0, 0, 0, 0)         ; Blank (Transparent)
	COLOR_MAGENTA    equ color(255, 0, 255, 255)   ; Magenta
	COLOR_RAYWHITE   equ color(245, 245, 245, 255) ; My own White (raylib logo)

%endif ; RAY_COLOR_INC
