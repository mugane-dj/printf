#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * run_printf - print formatted strings to console.
 * @format: formatted string.
 * @args: arguments of type va_list.
 * Return: number of chars printed exculding the null byte.
 */
int run_printf(const char *format, va_list args)
{
	int len = -1; /*if format is NULL return -1 as len*/

	if (format != NULL)
	{
		int index = 0;
		int (*op)(va_list);

		len = 0;

		while (format[index] != '\0')
		{
			if (format[index] == '%')
			{
				if (format[index + 1] == ' ' || format[index + 1] == '%')
				{
					len += write(1, &format[index], 1);
					index++;
				}
				else
				{
					op = get_converter(format[index + 1]);
					if (op)
						len += op(args);
					else
					{
						write(1, &format[index], 1);
						write(1, &format[index + 1], 1);
						len += 2;
					}
					index += 1;
				}
			}
			else
				len += write(1, &format[index], 1);
			index++;
		}
	}
	return (len);
}

/**
 * _printf - printd formatted strings to console.
 *
 * @format: formatted string.
 * Return: number of chars printed exculding the null byte.
 */

int _printf(const char *format, ...)
{
	int num;
	va_list args;

	va_start(args, format);

	num = run_printf(format, args);

	va_end(args);

	return (num);
}
