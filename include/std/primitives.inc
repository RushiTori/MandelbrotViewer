%ifndef PRIMITIVES_INC
%define PRIMITIVES_INC

%include "types_utils.inc"

define_type(char,    b, byte)
define_type(short,   w, word)
define_type(int,     d, dword)
define_type(long,    q, qword)

define_type(float,   d, dword)
define_type(double,  q, qword)

define_type(pointer, q, qword)

%endif ; PRIMITIVES_INC
