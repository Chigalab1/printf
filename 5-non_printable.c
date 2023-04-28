#include "main.h"

/**
 * print_non_printable -function prints non printable characters
 * @list: list of arguments
 * @buffer: buffer array
 * @flags: parameter to calculate active flags
 * @width: parameter to get width
 * @prec: precission parameter
 * @size: size argument
 *
 * Return: Length of char printed
 */
int print_non_printable(va_list list, char buffer[], int flags,
		int width, int prec, int size)
{
	int i = 0;
	int off = 0;
	char *str = va_arg(list, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	for (i = 0; str[i] != '\0'; i++)
	{
		if (is_printable(str[i]))
			buffer[i + off] = str[i];
		else
			off += append_hexa_code(str[i],
			buffer, i + off);
	}

	buffer[i + off] = '\0';

	return (write(1, buffer, i + off));
}

