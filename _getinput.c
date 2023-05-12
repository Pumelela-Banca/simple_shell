# include "main.h"
# include <stdlib.h>
# include <stdio.h>
/**
 * _getinput - function to get input from STDIN
 * Return: pointer to the string buffer
 */
char *_getinput(void)
{
	char *buff;
	size_t n = 1024;

	buff = malloc(n * sizeof(char));

	if ((getline(&buff, &n, stdin) == -1))
	{
		exit(0);
	}
	return (buff);
}
