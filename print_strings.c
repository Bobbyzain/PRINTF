#include "main.h"

/**
 * strings - printing strings
 * @written: the argument counter
 * @ap: variadic argument parameters
 * Return: always int
 */

int strings(int written, va_list ap)
{
	int i;
	char *str = va_arg(ap, char*);

	i = 0;
	while (str[i] != '\0')
		i++;
	written += write(1, str, i);
	return (written);
}
