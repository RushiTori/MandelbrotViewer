%ifndef INTTYPES_INC
%define INTTYPES_INC

%include "types_utils.inc"

define_type(int8,    b, byte)
define_type(int16,   w, word)
define_type(int32,   d, dword)
define_type(int64,   q, qword)
define_type(int128,  o, oword)

define_type(uint8,   b, byte)
define_type(uint16,  w, word)
define_type(uint32,  d, dword)
define_type(uint64,  q, qword)
define_type(uint128, o, oword)

%endif ; INTTYPES_INC
