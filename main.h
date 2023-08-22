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
int signed_integer_counter(int num);
char *signed_int_to_str(int num);
int *signed_num_size_gen(int num, int i);
int signed_int_spec(int written, va_list ap);
int pointer_writer(void *ptr);
int address_print(int written, va_list ap);
int uns_spec(int written, va_list ap);
char *dec_to_oct(unsigned int bin);
int uns_integer_counter(unsigned int num);
char *uns_int_to_str(unsigned int num);
int uns_int_spec(int written, va_list ap);
char *dec_to_bin(unsigned int bin);
void reverse_string(char *str, int length);
int integer_counter(int num);
char *int_to_str(int num);
int int_spec(int written, va_list ap);
int cap_hex_conv(int written, va_list ap);
char *dec_to_up_hex(unsigned int hex);
int low_hex_conv(int written, va_list ap);
char *dec_to_low_hex(unsigned int hex);
int oct_convert(int written, va_list ap);
int _printf_formats2(const char *ccc, int written, va_list ap);
int bin_convert(int written, va_list ap);
int space_integer_counter(int num);
char *space_int_to_str(int num);
int *space_num_size_gen(int num, int i);
int space_int_spec(int written, va_list ap);
int _strlen(const char *str);
char *rev_str(char *str);

#endif 
