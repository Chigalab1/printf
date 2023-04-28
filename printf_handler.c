#include "main.h"
/**
 * print_handler - Prints an argument based on its type
 * @fmt: a pointer to a character string that contains the
 *       format specifier for printing the arguments
 * @args: a va_list that contains the list of arguments to be printed
 * @ind: a pointer to an integer that keeps track of the current
 *       position in the format string
 * @buffer: a character array used to handle the output of the function
 * @flags: integer that stores the active flags for formatting the output
 * @width: integer that specifies the minimum width of the output
 * @prec: an integer that specifies the precision for floating-point types
 * @size: an integer that specifies the size of the argument
 * Return: 1 or 2 or -1 if an error occurs
 */
int print_handler(const char *fmt, int *ind, va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	int i, unknown_fmt_len = 0, num_char_print  = 0, ret = 0;
	fmt_t fmt_types[] = {{'c', print_char}, {'s', print_str}, {'%', print_per},
		{'R', print_rot13}, {'i', print_integer}, {'d', print_integer},
		{'b', print_u_bin}, {'u', print_unsignd}, {'o', print_oct}, {'x', print_hex},
		{'X', print_hex_upper}, {'S', print_non_printable}, {'r', print_str_rev},
		{'p', print_pointer}, {'\0', NULL}};

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(args, buffer, flags, width, prec, size));
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_fmt_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
		{
			ret = write(1, " ", 1);
			if (ret < 0)
				return (-1);
			unknown_fmt_len += ret;
		}
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		ret = write(1, &fmt[*ind], 1);
		if (ret < 0)
			return (-1);
		unknown_fmt_len += ret;
		num_char_print += unknown_fmt_len;
		return (num_char_print);
	}
	return (num_char_print);
}
