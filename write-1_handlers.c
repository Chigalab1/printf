#include "main.h"

/**
 * write_char_handler - function that prints a string
 * @ch: character types
 * @buffer: buffer array
 * @flags: arg to calculate active flags
 * @width: width parameter
 * @prec: precision specifier
 * @size: size parameterr
 *
 * Return: lenghth of char to print
 */
int write_char_handler(char ch, char buffer[], int flags, int width,
		int prec, int size)
{
	int i = 0;
	char pp = ' ';

	UNUSED(prec);
	UNUSED(size);

	if (flags & F_ZERO)
		pp = '0';

	buffer[i++] = ch;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[SIZE_OF_BUFF - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[SIZE_OF_BUFF - i - 2] = pp;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[SIZE_OF_BUFF - i -
					1], width - 1));
		else
			return (write(1, &buffer[SIZE_OF_BUFF - i - 1],
					width - 1) + write(1,
						&buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}


/**
 * number_write - function that prints a string
 * @is_neg: arguments
 * @i_d: character types
 * @buffer: Buffer array
 * @flags: arg to calculate active flags
 * @width: width argument
 * @prec: precission argument
 * @size: size parameter
 *
 * Return: lenghtth of char to print
 */
int number_write(int is_neg, int i_d, char buffer[], int flags,
		int width, int prec, int size)
{
	int str_len = SIZE_OF_BUFF - i_d - 1;
	char pp = ' ', ch_xt = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pp = '0';
	if (is_neg)
		ch_xt = '-';
	else if (flags & F_PLUS)
		ch_xt = '+';
	else if (flags & F_SPACE)
		ch_xt = ' ';

	return (num_write(i_d, buffer, flags, width, prec,
			str_len, pp, ch_xt));
}

/**
 * num_write - function that writes a number using buffer
 * @i_d: index at which the number starts
 * @buffer: buffer array
 * @flags: flag parameter
 * @width: width parameter
 * @prec: precision parameter
 * @str_len: number length
 * @pp: padding character
 * @c_xtra: extra character
 *
 * Return: length of printed char
 */
int num_write(int i_d, char buffer[], int flags, int width, int prec,
		int str_len, char pp, char c_xtra)
{
	int i, pp_strt = 1;

	if (prec == 0 && i_d == SIZE_OF_BUFF - 2 && buffer[i_d]
			== '0' && width == 0)
		return (0);
	if (prec == 0 && i_d == SIZE_OF_BUFF - 2 && buffer[i_d] == '0')
		buffer[i_d] = pp = ' ';
	if (prec > 0 && prec < str_len)
		pp = ' ';
	while (prec > str_len)
		buffer[--i_d] = '0', str_len++;
	if (c_xtra != 0)
		str_len++;
	if (width > str_len)
	{
		for (i = 1; i < width - str_len + 1; i++)
			buffer[i] = pp, buffer[i] = '\0';
		if (flags & F_MINUS && pp == ' ')
		{
			if (c_xtra)
				buffer[--i_d] = c_xtra;
			return (write(1, &buffer[i_d], str_len) +
				write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && pp == ' ')
		{
			if (c_xtra)
				buffer[--i_d] = c_xtra;
			return (write(1, &buffer[1], i - 1) +
				write(1, &buffer[i_d], str_len));
		}
		else if (!(flags & F_MINUS) && pp == '0')
		{
			if (c_xtra)
				buffer[--pp_strt] = c_xtra;
			return (write(1, &buffer[pp_strt], i - pp_strt) +
					write(1, &buffer[i_d], str_len - (1 - pp_strt)));
		}
	}
	if (c_xtra)
		buffer[--i_d] = c_xtra;
	return (write(1, &buffer[i_d], str_len));
}

/**
 * write_unsgnd - a function that writes an unsigned number
 * @is_neg: indicates if the num is negative or not
 * @ind: index of first character in the buffer
 * @buffer: array of chars to hold buffer
 * @flags: flags specifiers
 * @width: width specifier
 * @prec: the precision specifier
 * @size: the ize specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_neg, int ind, char buffer[],
	int flags, int width, int prec, int size)
{
	int length = SIZE_OF_BUFF - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (prec == 0 && ind == SIZE_OF_BUFF - 2 && buffer[ind] == '0')
		return (0);

	if (prec > 0 && prec < length)
		padd = ' ';

	while (prec > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer_handler - a function to write a memory address
 * @buffer: arrays to store buffer chars
 * @ind: index at which first character starts in buffer
 * @length: length of number printed
 * @width: the width specifier
 * @flags: flags specifier
 * @pp: characters representing the padding
 * @extra_c: extra char
 * @pp_start: the index at which padding start
 *
 * Return: Number of written chars.
 */
int write_pointer_handler(char buffer[], int ind, int length,
	int width, int flags, char pp, char extra_c, int pp_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = pp;
		buffer[i] = '\0';
		if (flags & F_MINUS && pp == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && pp == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && pp == '0')
		{
			if (extra_c)
				buffer[--pp_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pp_start], i - pp_start) +
				write(1, &buffer[ind], length - (1 - pp_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';

	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], SIZE_OF_BUFF - ind - 1));
}
