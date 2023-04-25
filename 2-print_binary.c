#include "main.h"

/**
 * print_bin - function that prints binary
 * @list: list of args
 * @buffer: buffer arrray to handle print
 * @flags: arg to calculate active flags
 * @width: width parameter
 * @prec: precission parameter
 * @size: size parameter
 *
 * Return: binary printed
 */
int print_bin(va_list list, char buffer[], int flags, int width, int prec,
		int size)
{

	unsigned int a, b, c, sum;
	unsigned int i[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	a = va_arg(list, unsigned int);
	b = 2147483648; /* (2^31) */
	i[0] = a / b;

	c = 1;
	while (c < 32)
	{
		b /= 2;
		i[c] = (a / b) % 2;
		c++;
	}
	for (c = 0, sum = 0, count = 0; c < 32; c++)
	{
		sum += i[c];
		if (sum || c == 31)
		{
			char z = '0' + i[c];

			write(1, &z, 1);
		}
	}
	return (count);
}
