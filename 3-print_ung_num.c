#include "main.h"

/**
 * print_unsigned - function that prints an unsigned number
 * @list: list of arguments
 * @buffer: buffer array
 * @flags: arg to calculate active flags
 * @width: width parameter
 * @prec: precission parameter
 * @size: size parameter
 *
 * Return: number of char printed
 */
int print_unsigned(va_list list, char buffer[], int flags, int width,
		int prec, int size)
{
	int a = SIZE_OF_BUFF - 2;
	unsigned long int n = va_arg(list, unsigned long int);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[SIZE_OF_BUFF - 1] = '\0';

	while (n > 0)
	{
		buffer[a--] = (n % 10) + '0';
		n /= 10;
	}
	a++;

	return (write_unsgnd(0, a, buffer, flags, width, prec, size));
}
