#include "main.h"

/**
 * signed_integer_counter - this is to check the length of the integer
 * @num: integer to be counted
 * Return: Integer
 */
int signed_integer_counter(int num)
{
	int len = 0;

	if (num < 0)
	{
		len++;	/* to deal with the negative signage */
		num = -num; /* Conversion of negative num to positiv num*/
	}
	else if (num > 0)
	{
		len++;	/* to deal with a positive sign */
		num = num;
	}
	if (num == 0)
	{
		len += 2;
		return (len);
	}
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * signed_int_to_str - integer conversion to string
 * @num: number input
 * Return: Integer
 */
char *signed_int_to_str(int num)
{
	int i, len, dig, start, end;
	char temp;
	char *buffer;
	int *x;

	len = signed_integer_counter(num);
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);	/* memory allocation failure */
	if (num == 0)
	{
		buffer[0] = '+';
		buffer[1] = '0';
		buffer[2] = '\0';
		return (buffer);
	}
	i = 0;
	buffer[0] = (num < 0) ? '-' : '+';
	x = signed_num_size_gen(num, i);
	num = x[0];
	i = x[1];
	while(num != 0)
	{
		dig = num % 10;
		buffer[i] = '0' + dig;
		num /= 10;
		i++;
	}
	buffer[len] = '\0';
	start = 1;
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
 * signed_num_size_gen - to check for number size
 * @num: the number whose size is searched for
 * @i: counter argument
 * Return: Int
 */
int *signed_num_size_gen(int num, int i)
{
	int *res;

	res = (int *)malloc(sizeof(int) * 2);
	if (res == NULL)
		return (NULL);
	if (num < 0)
	{
		i++;
		num = -num;
	}
	else if (num > 0)
	{
		i++;
		num = num;
	}
	res[0] = num;
	res[1] = i;

	return (res);
}

/**
 * signed_int_spec - to deal with the integer format specifier
 * @written: counting the arguments
 * @ap: parameter arguments
 * Return: Int
 */
int signed_int_spec(int written, va_list ap)
{
	int len, num = va_arg(ap, int);
	char *buffer = signed_int_to_str(num);

	if (buffer == NULL)
		return (written);

	len = signed_integer_counter(num);
	written += write(1, buffer, len);
	free(buffer);

	return (written);
}
