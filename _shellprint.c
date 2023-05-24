#include "main.h"

/**
 * _shellprint - prints shell promt
 *
 * Return: Void
 */

char *_shellprint(void)
{
	int z;
	char *buff = NULL;
	size_t n = 1024, i = 0;

	buff = malloc(n * sizeof(char));
	if (buff == NULL)
	{
		perror("Error: can't allocate memory");
		exit(1);
	}
	printstr("$ ");
	z = getline(&buff, &n, stdin);
	if (z == -1)
	{
		_putchar('\n');
		exit(0);
	}
	if (buff[0] == '\n')
		return (buff);
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			break;
		}
		i++;
	}
	return (buff);
}
