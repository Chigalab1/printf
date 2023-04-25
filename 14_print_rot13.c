#include "main.h"

/**
 * print_rot13 - a function to print any string in rot13
 * @list: list of arguments passed to function
 * @buffer: array of buffer
 * @flags: calculates active flags passed to the function
 * @width: width specifier
 * @prec: print precision specificier
 * @size: size specifier
 *
 * Return: the number of characters printed
 */

int print_rot13(va_list list, char buffer[],
		int flags, int width, int prec, int size)
{
	char c;
	char *str;
	unsigned int i, j;
	int count = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(AHYY)";
	}

	for (i = 0; str[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (str[i] == (input[j]))
			{
				c = output[j];
				write(1, &c, 1);
				count++;
				break;
			}
		}
		if (!input[j])
		{
			c = str[i];
			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}

