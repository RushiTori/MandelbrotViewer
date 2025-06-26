%ifndef THREAD_INC
%define THREAD_INC

%include "std.inc"

; number of threads that can be used by the program
MAX_THREAD_COUNT equ 12

; For the pthread_t type
define_type(pthread, q, qword)

; Creates a new thread
; int pthread_create (pthread_t* newthread, const pthread_attr_t* attr, void*(*start_routine)(void*), void* arg);
extern               pthread_create

; Joins a thread
; int pthread_join (pthread_t th, void** thread_return);
extern               pthread_join

%endif ; THREAD_INC
