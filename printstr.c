#include "main.h"

/**
 * printstr - prints a string to given stdout
 *
 * @s: given string
 *
 * Return: 1 for success
 */

int printstr(char *s)
{
	int count;

	for (count = 0; s[count] != '\0'; count++)
	{
		_putchar(s[count]);
	}
	return (1);
}
