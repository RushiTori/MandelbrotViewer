%ifndef TYPES_UTILS_INC
%define TYPES_UTILS_INC

; Macro for defining a new type, usage: define_type(name, size, deref)
; Will define the following:
;     name_t (for usage in var(), res(), array(), etc.)
;     name_p (for usage in deref operation in place of dword, ex: dword [addr] -> name_p [addr])
;     name_s (for usage in sizeof())
	%macro define_type_base 3
		%xdefine %1_t %2
		%xdefine %1_p %3
		struc %1_s
			struc_member(%1_t, val, 1)
		endstruc
	%endmacro

	%define define_type(name, size, deref) define_type_base name, size, deref

; Macro for declaring "variables", usage : var(scope, type, name, value)
	%macro var_base 4
		%3:
		%1 %3: data
		d%2 %4
	%endmacro

	%define var(scope, type, name, value) var_base scope, type, name, value

; Macro for reserving "variables", usage : res(scope, type, name)
	%macro res_base 3
		%3:
		%1 %3: data
		res%2 1
	%endmacro
	
	%define res(scope, type, name) res_base scope, type, name

; Macro for declaring "arrays", usage : array(scope, type, name, values...)
; Will also create: name_count (equ of the number of values), name_size (equ of the size in bytes of this array)
	%macro array_base 5-*
		%3:
		%1 %3: data
		d%2 %4
		%%second_value:
		d%2 %{5:-1}
		%3_size  equ $ - %3
		%3_count equ %3_size / (%%second_value - %3)
	%endmacro

	%define array(scope, type, name, values+) array_base scope, type, name, values

; Macro for reserving "arrays", usage : res_array(scope, type, name, size)
; Will also create: name_count (equ of size), name_size (equ of the size in bytes of this array)
	%macro res_array_base 4
		%3:
		%1 %3: data
		res%2 1
		%%second_value:
		res%2 (%4) - 1
		%3_size  equ $ - %3
		%3_count equ %3_size / (%%second_value - %3)
	%endmacro

	%define res_array(scope, type, name, size) res_array_base scope, type, name, size

; Macro for declaring "strings", usage : string(scope, name, chars...)
; Will also create: name_size (equ of the number of chars)
	%macro string_base 3+
			%2:
			%1 %2: data
			db          %3
			%2_size equ $ - %2
	%endmacro

	%define string(scope, name, values+) string_base scope, name, values

; Macro for declaring "strings", usage : res_string(scope, name, size)
; Will also create: name_size (equ of the number of chars)
	%macro res_string_base 3
			%2:
			%1 %2: data
			resb %3
			%2_size equ $ - %2
	%endmacro

	%define res_string(scope, name, size) string_base scope, name, size

; Macro for declaring functions, usage : func(scope, name)
	%macro func_base 2
		%2:
		%1 %2: function
	%endmacro

	%define func(scope, name) func_base scope, name

; Macro for declaring a struc member, usage struc_member(type, name, count)

	%macro struc_member_base 3
		.%2: res%1 %3
	%endmacro

	%define struc_member(type, name, count) struc_member_base type, name, count

; Macro for retrieving the size (in bytes) of a type, an array or a string, usage sizeof(name)

	%define sizeof(name) name %+ _size

; Magic macro for enums, do NOT undef
	%define enum_id 0

; Macro for resetting the current enum_id value, usage : reset_enum_value(value)
	%macro reset_enum_value_base 1
		%assign enum_id %1
	%endmacro

	%define reset_enum_value(value) reset_enum_value_base value

; Macro for adding a new "enum" value and increment enum_id, usage : add_enum(name)
	%macro add_enum_base 1
		%xdefine %1 enum_id
		%assign enum_id (enum_id + 1)
	%endmacro

	%define add_enum(name) add_enum_base name

; Macro for adding a new "enum" with a set value and set enum_id to value + 1, usage : add_enum_value(name, value)
	%macro add_enum_value_base 2
		%xdefine %1 %2
		%assign enum_id ((%2) + 1)
	%endmacro

	%define add_enum_value(name, value) add_enum_value_base name, value

%endif ; TYPES_UTILS_INC
