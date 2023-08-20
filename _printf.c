#include "main.h"

/**
 * _printf -  produces output according to a format
 * @format: string containing directives
 * return: always integer
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
			/* else */
				/* written == _printf_formats1(c, written, ap); * to handle format specifier */
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
