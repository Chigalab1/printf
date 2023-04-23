#include "main.h"

/*******  a fun to print hex into binary    ******/

/**
 * print_u_bin - a function to print unsigned int in binary
 *
 * @list: list of all arguments passed to function
 * @buffer: to contain array to print
 * @flags:  calculates active flags in function
 * @width: get width of print
 * @prec: specifies the number of digits to be printed
 * after the decimal point for floating point numbers
 *
 * @size: specifies the size of the data type to be printed
 *
 * Return: the binary number
 */

int print_u_bin(va_list list, char buffer[],
	int flags, int width, int prec, int size)
{
	unsigned int num, divisor, sum, index;
	unsigned int arr[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	num = va_arg(list, unsigned int);
	divisor = 2147483648;
	arr[0] = num / divisor;

	index = 1;
	while (index < 32)
	{
		divisor /= 2;
		arr[index] = (num / divisor) % 2;
		index++;
	}

	for (index = 0, sum = 0, count = 0; index < 32; index++)
	{
		sum += arr[index];
		if (sum || index == 31)
		{
			char z = '0' + arr[index];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

