#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * parse_inp - separates input string using delimiter and removes '\n'
 *
 * @buffer: string to separate
 *
 * Return: pointer to list strings
 */

char **parse_inp(char *buffer)
{
	char **new;
	char *delim, *tok = NULL;
	int i = 0, count;

	delim = ' ';
	new = malloc(10 * sizeof(char *));
	if (!new)
	{
		perror(": Memory allocation failed");
		exit(1);
	}
	tok = strtok(buffer, delim);
	while (!tok)
	{
		new[i] = _strdup(tok);
		tok = strtok(NULL, delim);
		i++;
	}
	new[i] = NULL;
	return (new);
}
