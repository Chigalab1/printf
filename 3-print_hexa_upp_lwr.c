#include "main.h"

/**
 * print_hexa - function that prints hexa in lwr and upp
 * @list: list of arg
 * @map_to: array of values to map number
 * @buffer: buffer array to handle print
 * @flags: parameter to calculate flags
 * @flag_ch: calculate active flag
 * @width: parameter to get width
 * @prec: precision parameter
 * @size: size parameter
 * @size: size
 *
 * Return: length of char printed
 */
int print_hexa(va_list list, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int prec, int size)
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
		buffer[a--] = map_to[n % 16];
		n /= 16;
	}

	if (flags & F_HASH && in_n != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, prec, size));
}

