#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define SIZE_OF_BUFF 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* PRINT SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - a defined structure for print_handler
 *
 * @fmt: a character type variable that holds the format
 *       specifier for the input string
 * @fn: pointer to a function that takes arguments
 */

struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};


/**
* typedef struct fmt fmt_t - structer defined for printf function
*
* @fmt: a character type variable that holds the
*       format specifier for the input string
* @fm_t: function alias
*/

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int print_handler(const char *fmt, int *i, va_list args,
		char buffer[], int flags, int width, int prec, int size);


/* handler function for some specifiers */
int size_handler(const char *format, int *i);
int flags_handler(const char *format, int *i);
int width_handler(const char *format, int *i, va_list args);
int prec_handler(const char *format, int *i, va_list args);



/***** a function that prints char, string, percent ****/
int print_char(va_list list, char buffer[],
		int flags, int width, int prec, int size);

int print_str(va_list list, char buffer[],
		__attribute__((unused)) int flags,
		__attribute__((unused)) int width,
		__attribute__((unused)) int prec,
		__attribute__((unused)) int size);

/** a function that prints % sign  **/
int print_per(__attribute__((unused)) va_list list,
		__attribute__((unused)) char buffer[],
		__attribute__((unused)) int flags,
		__attribute__((unused)) int width,
		__attribute__((unused)) int prec,
		__attribute__((unused)) int size);


/******* functions that handle print width ***********/

int write_char_handler(char c, char buffer[],
		int flags, int width, int precision, int size);

/******** print 'unsigned int' into binary  ********/

int print_u_bin(va_list list, char buffer[],
		int flags, int width, int prec, int size);


/***** a function that print pointer in hexadecimal *****/
int print_pointer(va_list list, char buffer[],
		int flags, int width, int prec, int size);


/******WRITE HANDLERS *******/

int write_pointer_handler(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);


/********** print rot13 ***************/
int print_rot13(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/****** a function that prints integer ******/
int print_integer(va_list list, char buffer[],
		int flags, int width, int prec, int size);

/******* flags handlers *********/
int flags_handler(const char *format, int *i);

/** Handle the precision for non-custom conversion specifiers **/
int prec_handler(const char  *format, int *i, va_list args);

/** Handle the field width for non-custom conversion specifiers **/
int width_handler(const char *format, int *i, va_list args);

/* Handle the "l" & 'h' length modifiers for non-custom conversion specifiers*/
int size_handler(const char *format, int *i);

 /*** TO BE REVISITED ***/
/* Functions to print numbers */
int print_int(va_list list, char buffer[],
	int flags, int width, int prec, int size);

/** A FUNCTION THAT PRINT UNSIGNED NUMBER **/
int print_unsigned(va_list list, char buffer[],
	int flags, int width, int prec, int size);

/** PRINT UNSIGNED NUMBER IN OCTAL ***/
int print_oct(va_list list, char buffer[],
	int flags, int width, int prec, int size);

/**  PRINT UNSIGNED NUMBER IN HEXADECIMAL ***/
int print_hex(va_list list, char buffer[],
	int flags, int width, int prec, int size);

/** UNSIGNED NUMBER IN UPPER HEXADECIMAL ***/
int print_hex_upper(va_list list, char buffer[],
	int flags, int width, int prec, int size);

/***** a function that prints  hexadecimal number in lower or upper **/
int print_hexa(va_list list, char map_to[],
char buffer[], int flags, char flag_ch, int width, int prec, int size);

/*** a function that  print non printable characters ***/
int print_non_printable(va_list list, char buffer[],
	int flags, int width, int prec, int size);

/*** a funcion to print memory address **** */
int print_pointer(va_list list, char buffer[],
	int flags, int width, int prec, int size);

/** a function that print string in reverse  **/
int print_str_rev(va_list list, char buffer[],
	int flags, int width, int prec, int size);

#endif

