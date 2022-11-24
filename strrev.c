#include <stdlib.h>
#include "main.h"

/**
 * _strrev - It takes a string and reverses it.
 *
 * @str: This is the string that will be reversed.
 *
 * Return: The string is being returned.
 */

char *_strrev(char *str)
{
	int i = 0, len;
	char c;

	if (!str)
		return (NULL);

	for (len = 0; str[i++]; len++)
		;
	/* Looping through the string and swapping the characters. */
	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}

	return (str);
}
