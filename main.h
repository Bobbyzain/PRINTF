#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int strings(int written, va_list ap);
int _printf_formats1(const char *cc, int written, va_list ap);
<<<<<<< HEAD
int address_print(int written, va_list ap);
int pointer_writer(void *ptr);
=======
int signed_integer_counter(int num);
char *signed_int_to_str(int num);
int *signed_num_size_gen(int num, int i);
int signed_int_spec(int written, va_list ap);
>>>>>>> 549e711b6c8fa119c8ec839bc0bad76b470edfed

#endif 
