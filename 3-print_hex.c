#include "main.h"

/**
 * print_hex - prints unsigned number in hexadecimal
 * @list: list of arguments
 * @buffer: buffer array
 * @flags: parameter to calculates active flags
 * @width: width parameter
 * @prec: precission argument
 * @size: size parameter
 * Return: length of char printed
 *
 */
int print_hex(va_list list, char buffer[], int flags, int width,
		int prec, int size)
{
	return (print_hexa(list, "0123456789abcdef", buffer,
			flags, 'x', width, prec, size));
}

/**
 * print_hex_upper - func that prints unsigned int in upper hexadecimal
 * @list: list of arguments
 * @buffer: buffer array
 * @flags: parameter to calculate active flags
 * @width: width parameter
 * @prec: precission parameter
 * @size: size parameter
 *
 * Return: number of char printed
 */
int print_hex_upper(va_list list, char buffer[], int flags, int width,
		int prec, int size)
{
	return (print_hexa(list, "0123456789ABCDEF", buffer, flags,
			'X', width, prec, size));
}
