#include "main.h"

void run_buff_print(char buffer[], int *buff_arr_i);

/**
 * do_printf - a function that perform printf command
 *
 * @format: format of the  arguments to be printed
 * @...: Vairable arguments passed to the function
 *
 * Return: num_char_print (the number printed arguments)
 */
int do_printf(const char *format, ...)
{
	int i;                       /* index for iteration*/
	int num_print = 0;     /* number of characters printed per iteration */
	int num_char_print = 0;       /* total number of characters printed */
	int flags; /* holds the active flags for the current format specifier */
	int width; /* holds the width specification */
	int prec; /* holds  maximum number of characters to be printed for strings */
	int size; /* specifies the size of the data type to be printed */
	int buff_arr_i = 0;  /* represents the current index of the buffer array  */
	va_list args;                /* list of arguments */
	char buffer[SIZE_OF_BUFF];      /* buffer to hold characters to be printed */

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_arr_i++] = format[i];

			if (buff_arr_i == SIZE_OF_BUFF)
			{
				run_buff_print(buffer, &buff_arr_i);
			}
			num_char_print++;
		}
		else
		{
			run_buff_print(buffer, &buff_arr_i);

			flags = flags_handler(format, &i);
			width = width_handler(format, &i, args);
			prec = prec_handler(format, &i, args);
			size = size_handler(format, &i);
			++i;

			num_print = print_handler(format, &i, args, buffer,
				flags, width, prec, size);

			if (num_print == -1)
			{
				return (-1);
			}
			num_char_print = num_char_print + num_print;
		}
	}

	run_buff_print(buffer, &buff_arr_i);

	va_end(args);

	return (num_char_print);
}

/**
 * run_buff_print - a function that prints available buffer
 *
 * @buffer: an array of characters thats to be printed
 * @buff_arr_i: pointer to the index of the buffer array (length of array)
 *
 * Return: nothing
 */

void run_buff_print(char buffer[], int *buff_arr_i)
{
	if (*buff_arr_i > 0)
	{
		write(1, &buffer[0], *buff_arr_i);
	}

	*buff_arr_i = 0;
}
