#include "main.h"

/**
 * _strlen - count len of string
 *
 * @s: string to be counted
 *
 * Return: lenght of string
 */

int _strlen(char *s)
{
	int len, stop;

	if (*s == '\0')
	{
		return (0);
	}

	for (len = 1; len < 1000; len++)
	{
		stop = *(s + len);

		if (stop == '\0')
		{
			return (len);
		}
	}
	return (0);
}
