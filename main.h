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
int address_print(int written, va_list ap);
int pointer_writer(void *ptr);

#endif 
