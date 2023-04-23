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

int do_printf(const char *format, ...);
int print_handler(const char *fmt, int *i,
va_list args, char buffer[], int flags, int width, int prec, int size);


/* handler function for some specifiers */
int size_handler(const char *format, int *i);
int flags_handler(const char *format, int *i);
int width_handler(const char *format, int *i, va_list args);
int prec_handler(const char *format, int *i, va_list args);


#endif

