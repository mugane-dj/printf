#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * convert_c - handles 'c' format specifier
 *             and prints character to stdout.
 * @arg: list of char arguments passed.
 * Return: characters printed.
 */

int convert_c(va_list arg)
{
	char c;

	c = va_arg(arg, int);

	return (write(1, &c, 1));
}

/**
 * convert_s - handles format specifier 's'
 *             and prints string to stdout.
 * @arg: list of arguments passed.
 * Return: string chars printed.
 */

int convert_s(va_list arg)
{
	int index;
	char *str;

	str = va_arg(arg, char *);

	if (str == NULL)
		str = "(nil)";
	for (index = 0; str[index] != '\0'; index++)
		write(1, &str[index], 1);

	return (index);
}

/**
  * convert_d - handles format specifier 'd'
  *		and prints string to stdout.
  * @arg: list of arguments passed.
  * Return: characters printed.
  */

int convert_d(va_list arg)
{
	int num;
	int index;
	char tmp[20] = {0};

	num = va_arg(arg, int);

	_itoa(num, tmp, 10);

	for (index = 0; tmp[index] != '\0'; index++)
		write(1, &tmp[index], 1);
	return (index);
}

/**
  * convert_i - handles format specifier 'i'
  *		and prints string to stdout.
  * @arg: list of arguments passed.
  * Return: characters printed.
  */

int convert_i(va_list arg)
{
	return (convert_d(arg));

}

