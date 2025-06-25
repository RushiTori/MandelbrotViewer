%ifndef MANDELBROT_INC
%define MANDELBROT_INC

%include "raylib.inc"
%include "std.inc"

; Max number of iteration of the mandelbrot algorith per pixel
MAX_ITER equ 100

; Initializes some states for the mandelbrot computation
; void init_mandelbrot(void);
extern init_mandelbrot

; Frees the states allocated by init_mandelbrot
; void free_mandelbrot(void);
extern free_mandelbrot

; Updates the states of Mandelbrot (zoom, pan, etc.)
; void update_mandelbrot(void);
extern update_mandelbrot

; Renders the Mandelbrot Set
; void render_mandelbrot(void);
extern render_mandelbrot

%endif ; MANDELBROT_INC
