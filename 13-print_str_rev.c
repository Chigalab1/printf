#include "main.h"
#include <stdlib.h>

/**
 * print_str_rev - prints string in reverse
 * @list: list of argument
 * @buffer: buffer array to handle
 * @flags: parameter to calulate active flag
 * @width: width parameter
 * @prec: prec parameter
 * @size: size parameter
 *
 * Return: Length of char printed
 */
int print_str_rev(va_list list, char buffer[], int flags, int width,
		int prec, int size)
{
	char *str;
	int i, j = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(list, char *);

	if (str == NULL)
	{
		UNUSED(prec);

		str = ")Null(";
	}

	for (i = 0; str[i]; i++)
	{
		;
	}

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		j++;
	}
	return (j);
}
