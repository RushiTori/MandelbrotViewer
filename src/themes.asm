bits    64
default rel

%include "themes.inc"

section .rodata

var(static, double_t, uint8max_d, 255.0)

var(static, double_t, hue_max_d, 360.0)
var(static, double_t, hue_phase_range_d, 120.0)
var(static, double_t, hue_red_start_d, 0.0)
var(static, double_t, hue_green_start_d, 120.0)
var(static, double_t, hue_blue_start_d, 240.0)
var(static, float_t, one_f, 1.0)

section .text

%macro theme_hue_phase_base_macro 1
	xor rax, rax
	cmp dil, false
	jne .end

	mulsd    xmm0, double_p [hue_phase_range_d]
	addsd    xmm0, double_p [%1]
	cvtsd2ss xmm0, xmm0

	movss xmm1, float_p [one_f]
	movss xmm2, xmm1

	jmp ColorFromHSV

	.end:
	or eax, A_MASK
	ret
%endmacro

%define theme_hue_phase_base(hue_phase_start) theme_hue_phase_base_macro hue_phase_start

; Color theme_gray_scale(double, bool);
func(global, theme_gray_scale)
	xor rax, rax
	cmp dil, false
	jne .end

	mulsd    xmm0, double_p [uint8max_d]
	cvtsd2si rax,  xmm0
	mov      rdx,  0x01010101
	mul      edx

	.end:
	or eax, A_MASK
	ret

; Color theme_hue_full(double, bool);
func(global, theme_hue_full)
	xor rax, rax
	cmp dil, false
	jne .end

	mulsd    xmm0, double_p [hue_max_d]
	cvtsd2ss xmm0, xmm0

	movss xmm1, float_p [one_f]
	movss xmm2, xmm1

	jmp ColorFromHSV

	.end:
	or eax, A_MASK
	ret

; Color theme_hue_red(double, bool);
func(global, theme_hue_red)
	theme_hue_phase_base(hue_red_start_d)

; Color theme_hue_green(double, bool);
func(global, theme_hue_green)
	theme_hue_phase_base(hue_green_start_d)

; Color theme_hue_blue(double, bool);
func(global, theme_hue_blue)
	theme_hue_phase_base(hue_blue_start_d)
