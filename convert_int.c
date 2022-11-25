#include "main.h"
#include <stdlib.h>

/**
 * _itoa - converts integer to string.
 *
 * @i: int to be converted.
 * @str: A pointer to output area in memory
 * @base: The base of the integer to be converted.
 * Return: string.
 */

char *_itoa(int i, char *str, int base)
{
	int index = 0;
	int rem;
	int sign = 0;

	if (i == 0)
	{
		str[index++] = '0';
		str[index] = '\0';
		return (str);
	}

	if (i < 0 && base == 10)
	{
		sign = 1;
		i = -i;
	}

	while (i != 0)
	{
		rem = i % base;
		if (rem > 9)
		{
			str[index++] = (rem - 10) + 'a';
		}
		else
			str[index++] = rem + '0';
		i = i / base;
	}

	if (sign)
		str[index++] = '-';
	str[index] = '\0';

	return (_strrev(str));
}
