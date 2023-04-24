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

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int print_handler(const char *fmt, int *i,
va_list args, char buffer[], int flags, int width, int prec, int size);


/* handler function for some specifiers */
int size_handler(const char *format, int *i);
int flags_handler(const char *format, int *i);
int width_handler(const char *format, int *i, va_list args);
int prec_handler(const char *format, int *i, va_list args);



/***** a function that prints char, string, percent ****/
int print_char(va_list list, char buffer[],int flags, int width, int prec, int size);
int print_str(va_list types, char buffer[],
                __attribute__((unused)) int flags,
                __attribute__((unused)) int width,
                __attribute__((unused)) int prec,
                __attribute__((unused)) int size);

int print_percent(__attribute__((unused)) va_list types,
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
int print_pointer(va_list list, char buffer[], int flags, int width, int prec, int size);


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

#endif

