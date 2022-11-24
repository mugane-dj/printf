#include "main.h"
#include <stdlib.h>

/**
 * _itoa - converts integer to string.
 *
 * @i: int to be converted.
 * @output: A pointer to output area in memory
 * @base: The base of the integer to be converted.
 * Return: string.
 */

char *_itoa(int i, char *output, int base)
{
	int num;
	int sign;
	char *str = output;

	/*check if int is positive*/
	sign = 0;
	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}

	/*Convert int to ASCII*/

	while (i)
	{
		num = i % base;

		if (num > 9)
		{
			*str = ('A' + num - 10);
		}

		else
			*str = '0' + num;
		i = i / base;
		str++;
	}
	/*Add negative sign back*/

	if (sign)
	{
		*str++ = '-';
	}

	/*Add null byte*/

	*str = '\0';

	return (_strrev(output));
}
