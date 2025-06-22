%ifndef STDBOOL_INC
%define STDBOOL_INC

%include "types_utils.inc"

define_type(bool, b, byte)

true  equ 1
false equ 0

%endif ; STDBOOL_INC
