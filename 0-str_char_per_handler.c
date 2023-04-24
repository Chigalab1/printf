#include "main.h"


/*******   a function that prints characters 'c'   ***********/

/**
 * print_char - a function that prints characters
 * @list: list of arguments to be printed
 * @buffer: to contain array
 * @flags: determines actives flags to be handled
 * @width: width determiner
 * @prec: precision specifier
 * @size: holds the size specifier for the current format specifier
 *
 * Return: the number of characters printed
 */

int print_char(va_list list, char buffer[], int flags,
		int width, int prec, int size)
{
	char c;

	c = va_arg(list, int);

	return (write_char_handler(c, buffer, flags, width, prec, size));
}

/********a function that print strings ***********/
/**
 * print_str - a function that prints string
 *
 * @list: list a of arguments passed to the function
 * @buffer: array of string
 * @flags:  for calculating active flags passed
 * @width: get width of string
 * @prec: specifies the number of digits to be printed
 * @size: specifies the size of the data type to be printed
 *
 * Return: string printed
 */
int print_str(va_list list, __attribute__((unused)) char buffer[],
		__attribute__((unused)) int flags,
		__attribute__((unused)) int width,
		__attribute__((unused)) int prec,
		__attribute__((unused)) int size)
{
	int i;
	int str_len = 0;
	char *str;

	str = va_arg(list, char *);

	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
		{
			str = "      ";
		}
	}

	while (str[str_len] != '\0')
		str_len++;

	if (prec >= 0 && prec < str_len)
		str_len = prec;
	if (width > str_len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], str_len);
			for (i = width - str_len; i > 0; i--)
			{
				write(1, " ", 1);
			}
			return (width);
		}
		else
		{
			for (i = width - str_len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], str_len);
			return (width);
		}
	}
	return (write(1, str, str_len));
}

/**
 * print_per - a function that prints a percent sign
 * @list: list of arguments to print
 * @buffer: to hold array
 * @flags:  calculates all active flags passed
 * @width: specifies the minimum width of the output
 * @prec: specifies the number of digits to be printed
 * @size: the print size specifier
 * Return: the percentage sign
 */
int print_per(__attribute__((unused)) va_list list,
	__attribute__((unused)) char buffer[],
	__attribute__((unused)) int flags,
	__attribute__((unused)) int width,
	__attribute__((unused)) int prec,
	__attribute__((unused)) int size)
{
	return (write(1, "%%", 1));
}


