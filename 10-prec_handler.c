#include "main.h"

/**
 * prec_handler - function that handle the precision for
 * non-custom conversion specifiers
 * @format: formatted string to print
 * @i: arguments to be printed
 * @args: list of arguments
 *
 * Return: prec
 */
int prec_handler(const char  *format, int *i, va_list args)
{
	int c_i = *i + 1;
	int prec = -1;

	if (format[c_i] != '.')
		return (prec);

	prec = 0;

	c_i += 1;
	while (format[c_i] != '\0')
	{
		if (is_digit(format[c_i]))
		{
			prec *= 10;
			prec += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			prec = va_arg(args, int);
			break;
		}
		else
			break;

		c_i++;
	}

	*i = c_i - 1;

	return (prec);
}
