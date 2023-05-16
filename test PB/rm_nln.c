#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * rm_nln - removes newline char from string
 *
 * @s: string to remove from
 *
 * Return: new string without newline
 */

char *rm_nln(char *s)
{
	char *str, *pos, *rez;

	str = malloc(strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	strncpy(str, s, strlen(s));
	pos = strchr(str, '\n');
	if (pos != NULL)
	{
		*pos = '\0';
		rez = strdup(str);
		free(str);
		return (rez);
	}
	else
	{
		free(str);
		return (s);
	}
}
