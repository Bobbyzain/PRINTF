#include "main.h"

/**
 * _printf -  produces output according to a format
 * @format: string containing directives
 * Return: always integer
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int written = 0;
	const char *c = format;


	va_start(ap, format);
	for (; *c != '\0'; c++)
	{
		if (*c == '%')
		{
			c++;	/* to move beyond the % */
			if (*c == '\0')	/* end of string (unexpected) */
				break;
			if (*c == '%')
			{
				write(1, "%", 1);	/* handle '%%' case */
				written++;
			}
			else
				written = _printf_formats1(c, written, ap); /*to handle format specifier */
		}
		else
		{
			if (*c == 'd' || *c == 'i' || *c == 'f')
			{
				c--;
				if (*c == '+' || *c == ' ')
				{
					c--;
					c += (*c == '%') ? 3 : 2;
				}
				else
					c++;
			}
			write(1, c, 1);	/* this is a regular character */
			written++;
		}
	}
	va_end(ap);
	return (written);
}
/**
 * _printf_formats1 - continuation of the printf variadic function
 * @cc: string containing directives or specifiers
 * @written: argument parameters tracker
 * @ap: argument parameters
 * Return: Int
 */
int _printf_formats1(const char *cc, int written, va_list ap)
{
	const char *c = cc;
	char chc;

	if (*c == 'u')
		written = uns_spec(written, ap);
	else if (*c == 'c')
	{
		chc = va_arg(ap, int); /* to handle for character format*/
		written += write(1, &chc, 1);
	}
	else if (*c == 'p')
		written = address_print(written, ap); /*to handle printing of addresses */
	else if (*c == '+')
	{
		c++;
		if (*c == 'd' || *c == 'i' || *c == 'f')
			written = signed_int_spec(written, ap); /* to handle signs in stdout */
		else
		{
			c--;
			write(1, c, 1);
		}
	}
	else if (*c == 'd' || *c == 'i')
		written = int_spec(written, ap); /* Handle integer format */
	else if (*c == 's')
		written = strings(written, ap); /* to handle string format */
	else
		 written = _printf_formats2(c, written, ap); /*to handle format specifier */
	return (written);
}
/**
 * _printf_formats2 - Continuation of the main function
 * @ccc: format expected
 * @written: argument counter
 * @ap: argument parameter
 * Return: Always 0
 */
int _printf_formats2(const char *ccc, int written, va_list ap)
{
	const char *c = ccc;

	if (*c == 'o')
		written = oct_convert(written, ap); /* Handle octal format */
	else if (*c == 'x')
		written = low_hex_conv(written, ap); /* Handle lowercase hexadecimal */
	else if (*c == 'X')
		written = cap_hex_conv(written, ap); /* Handle for uppercase hexadecimal */
	return (written);
}
