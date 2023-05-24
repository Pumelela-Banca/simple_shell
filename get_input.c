# include "main.h"

/**
 * get_input - function to get input (non- interactive)
 * Return: buffer
 */

char *get_input(void)
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
	z = getline(&buff, &n, stdin);
	if (z == -1)
	{
		exit(0);
	}
	else if (z == 1)
	{
		free(buff);
		exit(0);

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
