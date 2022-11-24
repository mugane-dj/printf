#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - printd formatted strings to console.
 *
 * @format: formatted string.
 * Return: number of chars printed exculding the null byte.
 */

int _printf(const char *format, ...)
{
	int len = -1; /*if format is NULL return -1 as len*/

	if (format != NULL)
	{
		int index = 0;
		int (*op)(va_list);
		va_list param;

		va_start(param, format);
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
				else if (format[index + 1] != '\0')
				{
					op = get_converter(format[index + 1]);
					if (op)
						len += op(param);
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
		va_end(param);
	}
	return (len);
}
