#include "main.h"

/**
 * print_integer - a function that prints integers
 * @list: list of arguments
 * @buffer: buffer array
 * @flags: arg to calculate active flags
 * @prec: precission specifiers
 * @width: arg to get width
 * @size: size specifier
 *
 * Return: number of chars
 */
int print_integer(va_list list, char buffer[],
		int flags, int width, int prec, int size)
{
	int i = SIZE_OF_BUFF - 2;
	int is_neg = 0;
	long int n = va_arg(list, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
	{
		buffer[i--] = '0';
	}

	buffer[SIZE_OF_BUFF - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num = num / 10;
	}

	i++;

	return (number_write(is_neg, i, buffer, flags, width, prec, size));
}
