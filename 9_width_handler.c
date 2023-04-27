#include "main.h"

/**
 * width_handler - Handle the field width for non-custom conversion specifiers
 * @format: formatted string to print
 * @i: list of arguments to print
 * @args: argument lists
 *
 * Return: width
 */
int width_handler(const char *format, int *i, va_list args)
{
	int c_i;
	int width = 0;

	for (c_i = *i + 1; format[c_i] != '\0'; c_i++)
	{
		/**
		 *
		if (format[c_i] == '*')
		{
			c_i++;
			width = va_arg(args, int);
			break;
		}
		*/
		if (is_digit(format[c_i]))
		{
			width *= 10;
			width += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			width = va_arg(args, int);
			break;
		}
		else
		{
			break;
		}
	/*	c_i++; */
	}

	*i = c_i - 1;

	return (width);
}
