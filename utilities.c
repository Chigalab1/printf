#include "main.h"

/**
 * is_printable - whether a given character is a printable character or not
 * @c: is an ASCII character to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}

	return (0);
}

/**
 * append_hexa_code - appends the hexadecimal code for an ASCII
 *                   char to a buffer of characters
 *
 * @buffer: array to store buffer
 * @i: index at which to start appending characters
 * @ascii: ASSCI codes
 *
 * Return: Always 3
 */
int append_hexa_code(char ascii, char buffer[], int i)
{
	char match_to[] = "0123456789ABCDEF";

	/* The hexa format code is always 2 digits long */
	if (ascii < 0)
	{
		ascii *= -1;
	}

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = match_to[ascii / 16];
	buffer[i] = match_to[ascii % 16];

	return (3);
}

/**
 * is_digit - a function that determines if an input is digit or not
 * @c: characters to be evaluated
 *
 * Return: 1 if character is a digit, or 0 otherwise
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * convert_size_number - a function that cast a number to the specified size
 * @input_number: the number to be casted
 * @size: specifies the desired size that the num argument should be casted to
 *
 * Return: the casted value of input_number
 */

long int convert_size_number(long int input_number, int size)
{
	if (size == S_LONG)
		return (input_number);

	else if (size == S_SHORT)
		return ((short)input_number);

	return ((int)input_number);
}

/**
 * convert_size_unsgnd - a function that cast a number to the specified size
 * @input_number: the number to be casted
 * @size: specifies the desired size that the num argument should be casted to
 *
 * Return: casted value of input_number
 */
long int convert_size_unsgnd(unsigned long int input_number, int size)
{
	if (size == S_LONG)
		return (input_number);
	else if (size == S_SHORT)
		return ((unsigned short)input_number);

	return ((unsigned int)input_number);
}
