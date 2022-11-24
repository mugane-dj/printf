#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_converter - function pointer that matches specifier
 *		   to converter function.
 * @c: format specifier.
 * Return: converter functions that matches the specifier.
 */

int (*get_converter(char c))(va_list)
{
	int index;
	convert ops[] = {
		{"c", convert_c},
		{"s", convert_s},
	};

	for (index = 0; ops[index].symbol != NULL; index++)
	{
		if (*ops[index].symbol == c)
			return (ops[index].op);
	}

	return (NULL);
}
