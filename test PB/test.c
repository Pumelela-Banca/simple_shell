#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * parse_inp - splits string up using delimiter
 *
 * @str: string to be split
 * @delim: Delimiter to look at
 *
 * Return: char string with all split parts
 */

char **parse_inp(char *str, char *delim)
{
	char **vars;
	char *token;
	int size, count;

	size = 5;
	vars = malloc(sizeof(char *) * size);
	if (vars == NULL)
	{
		/*prompt("Memory allocation failed\n");*/
		exit(1);
	}
	count = 0;
	token = strtok(str, delim);
	while (token != NULL)
	{
		if (count == size)
		{
			/*size *= 2; * increase size of array*
			vars = realloc(vars, sizeof(char *) * 11, sizeof(char *) * size);
			if (vars == NULL)
			{
				/*prompt("Memory allocation failed\n");
				exit(1);
			}*/
		}
		vars[count] = malloc(sizeof(char) * (strlen(token) + 1));
		/*rm_cmnt(token);*/
		strcpy(vars[count], rm_nln(token));
		count++;
		token = strtok(NULL, delim);
	}
	vars[count] = NULL;
	return (vars);
}



void main(void)
{
	char **new;
	char *buff;
	size_t n = 1024;
	int bb, nn;
	
	nn = 0;
	printf("$ ");
	buff = malloc(n * sizeof(char));
	bb = getline(&buff, &n, stdin);
	new = parse_inp(buff, " ");

	while (*new != NULL)
	{
		printf("%s\n", *new++);
	}
}























