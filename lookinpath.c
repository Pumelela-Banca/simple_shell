#include "main.h"

/**
 * lookinpath - prints each item on path
 *
 * @envp: enviroment variables
 *
 * Return: void
 */

void lookinpath(char *envp[])
{
	char *buff = NULL;
	char *token = NULL;

	buff = _getenv("PATH");
	token = strtok(buff, ":");

	do 
	{
		printstr(token);
		_putchar('\n');
		token = strtok(NULL, ":");
	} while (token != NULL);
}
