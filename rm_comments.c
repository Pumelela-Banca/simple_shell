#include "main.h"

/**
 * rm_comments - removes comments
 *
 * @str: string to remove comments from
 *
 * Return: void
 */

void rm_comments(char *str)
{
	int i, found = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '#' || found > 0)
		{
			str[i] = '\0';
			found++;
		}
	}
}
