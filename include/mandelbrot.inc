%ifndef MANDELBROT_INC
%define MANDELBROT_INC

%include "themes.inc"
%include "thread.inc"

; Max number of iteration of the mandelbrot algorithm per pixel
MAX_ITER equ 100

; Initializes some states for the mandelbrot computation
; void init_mandelbrot(void);
extern init_mandelbrot

; Frees the states allocated by init_mandelbrot
; void free_mandelbrot(void);
extern free_mandelbrot

; Sets the current function used to compute the color of the mandelbrot (default: theme_gray_scale)
;     double: [0...1] percentage of the iteration done over MAX_ITER before reaching infinity
;     bool: shot-hand for (double == 1.0), tells if the current position did NOT reach infinity in MAX_ITER iterations
; void set_mandelbrot_theme_callback(Color (*f)(double, bool))
extern set_mandelbrot_theme_callback

; Updates the states of Mandelbrot (zoom, pan, etc.)
; void update_mandelbrot(void);
extern update_mandelbrot

; Renders the Mandelbrot Set
; void render_mandelbrot(void);
extern render_mandelbrot

%endif ; MANDELBROT_INC
