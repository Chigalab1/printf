#include "main.h"
/**
 * print_handler - Prints an argument based on its type
 * @fmt: a pointer to a character string that contains the
 *       format specifier for printing the arguments
 * @args: a va_list that contains the list of arguments to be printed
 * @ind: a pointer to an integer that keeps track of the current
 *       position in the format string
 * @buffer: a character array used to handle the output of the function
 * @flags: an integer that stores the active flags for formatting the output
 * @width: an integer that specifies the minimum width of the output
 * @prec: an integer that specifies the precision for floating-point types
 * @size: an integer that specifies the size of the argument
 * Return: 1 or 2 or -1 if an error occurs
 */
int print_handler(const char *fmt, int *ind, va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	int i = 0, unknown_fmt_len = 0, num_char_print  = -1;
	fmt_t fmt_types[] = {{'c', print_char}, {'s', print_str}, {'R', print_rot13},
		{'i', print_integer}, {'d', print_integer}, {'b', print_u_bin},
		{'%', print_per}, {'S', print_non_printable}, {'r', print_str_rev},
		{'u', print_unsigned}, {'\0', NULL}};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(args, buffer, flags, width, prec, size));
	}
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_fmt_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
		{
			unknown_fmt_len += write(1, " ", 1);
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
		unknown_fmt_len += write(1, &fmt[*ind], 1);
		return (unknown_fmt_len);
	}
	return (num_char_print);
}
