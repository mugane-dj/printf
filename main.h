#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>

/**
 * struct converter - A new type struct converter.
 * @symbol: member for specifier arg.
 * @op: member function.
 */

typedef struct converter
{
	char *symbol;
	int (*op)(va_list);
} convert;

/*Functions implemented*/

int (*get_converter(char c))(va_list);
int convert_c(va_list arg);
int convert_s(va_list arg);
int convert_d(va_list arg);
int convert_i(va_list arg);
char *_strrev(char *str);
char *_itoa(int i, char *output, int base);
int _printf(const char *format, ...);

#endif
