#include "main.h"
#include <stdlib.h>

/**
 * print_str_rev - prints string in reverse
 * @list: list of argument
 * @buffer: buffer array to handle
 * @flags: parameter to calulate active flag
 * @width: width parameter
 * @prec: precission parameter
 * @size: size parameter
 *
 * Return: Length of char printed
 */
int print_str_rev(va_list list, char buffer[], int flags, int width,
		int prec, int size)
{
	char *str;
	int i, j = 0;
	char *rev_str;

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
	i = 0;

	while (str[i])
	{
		;
		i++;
	}
	rev_str = malloc(i + 1);

	if (rev_str == NULL)
	{
		return (-1);
	}
	for (i = i - 1; i >= 0; i--)
	{
		rev_str[j] = str[i];
		j++;
	}
	write(1, rev_str, j);
	free(rev_str);

	return (j);
}
