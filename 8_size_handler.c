#include "main.h"

/**
 * size_handler - for calculating the size to cast the argument,
 *                based on any size modifiers "(l or h)" that appear
 *                in the format string
 *
 * @format: determine whether a size modifier character (either 'l' or 'h')
 *          is present in the format string
 *
 * @i: list of arguments passed to the funtion to  print
 *
 * Return: the size of argument
 */

int size_handler(const char *format, int *i)
{
	int current_i;
	int size = 0;

	current_i = *i + 1;

	if (format[current_i] == 'l')
		size = S_LONG;

	else if (format[current_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = current_i - 1;

	else
		*i = current_i;

	return (size);
}
