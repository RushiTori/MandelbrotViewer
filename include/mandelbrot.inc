%ifndef MANDELBROT_INC
%define MANDELBROT_INC

%include "raylib.inc"
%include "std.inc"

; Max number of iteration of the mandelbrot algorith per pixel
MAX_ITER equ 100

; Updates the states of Mandelbrot (zoom, pan, etc.)
; void update_mandelbrot(void);
extern update_mandelbrot

; Renders the Mandelbrot Set
; void render_mandelbrot(void);
extern render_mandelbrot

%endif ; MANDELBROT_INC
