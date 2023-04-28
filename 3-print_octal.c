#include "main.h"

/**
 * print_oct - function that prints unsigned number in octal
 * @list: list of arguments
 * @buffer: buffer array to handle print
 * @flags: parameter to calculate active flags
 * @width: width parameter to handle
 * @prec: precission parameter
 * @size: size parameter
 *
 * Return: number of char printed
 */
int print_oct(va_list list, char buffer[], int flags, int width,
		int prec, int size)
{
	int a = SIZE_OF_BUFF - 2;
	unsigned long int n = va_arg(list, unsigned long int);
	unsigned long int in_n = n;

	UNUSED(width);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[a--] = '0';

	buffer[SIZE_OF_BUFF - 1] = '\0';

	while (n > 0)
	{
		buffer[a--] = (n % 8) + '0';
		n /= 8;
	}

	if (flags & F_HASH && in_n != 0)
		buffer[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buffer, flags, width,
				prec, size));
}
