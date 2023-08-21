#include "main.h"


/**
 * uns_integer_counter - checks length of integer
 *
 * @num: integer to be counted
 *
 * Return: length as integer
 */
int uns_integer_counter(unsigned int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * uns_int_to_str - converts int to str
 *
 * @num: number to be converted
 *
 * Return: nothing
 */
char *uns_int_to_str(unsigned int num)
{
	int i, len, dig, start, end;
	char temp;
	char *buffer;

	len = uns_integer_counter(num);
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL); /* Failed to allocate memory */
	if (num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\n';
		return (buffer);
	}
	i = 0;
	while (num != 0)
	{
		dig = num % 10;
		buffer[i] = '0' + dig;
		num /= 10;
		i++;
	}
	buffer[len] = '\0';
	start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}
	return (buffer);
}

/**
 * uns_int_spec - handles integer format
 *
 * @written: argument counter
 * @ap: argument parameter
 *
 * Return: written as integer
 */
int uns_int_spec(int written, va_list ap)
{
	int len, num = va_arg(ap, int);
	char *buffer = uns_int_to_str(num);

	if (buffer == NULL)
		return (written);
	len = uns_integer_counter(num);
	written += write(1, buffer, len);
	free(buffer);
	return (written);
}

