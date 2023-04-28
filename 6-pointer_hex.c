#include "main.h"

/**
 * print_pointer - a function that prints pointers in hexadecimals
 *
 * @list: list of areguments passed to function
 * @buffer: array of arg to print
 * @flags: calculates availables flags
 * @width: print width specifier
 * @prec: specifies numb. of digits to be printed
 * @size: size of chars to be printed
 *
 * Return: list of characters printed
 */

int print_pointer(va_list list, char buffer[], int flags,
		int width, int prec, int size)
{
	char str_flags = 0;
	int i = SIZE_OF_BUFF - 2;
	int p_len = 2, pad_start = 1;
	unsigned long p_address;
	char hex_match[] = "0123456789abcdef";
	char pad_flag = ' ';
	void *addrs = va_arg(list, void *);

	UNUSED(size);
	UNUSED(width);

	if (addrs == NULL)
	{
		return (write(1, "(nil)", 5));
	}

	buffer[SIZE_OF_BUFF - 1] = '\0';
	UNUSED(prec);

	p_address = (unsigned long)addrs;

	while (p_address > 0)
	{
		buffer[i--] = hex_match[p_address % 16];
		p_address /= 16;
		p_len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad_flag = '0';

	if (flags & F_PLUS)
		str_flags = '+', p_len++;

	else if (flags & F_SPACE)
		str_flags = ' ', p_len++;
	i++;

	return (write_pointer_handler(buffer, i, p_len, width, flags,
				pad_flag, str_flags, pad_start));
}
