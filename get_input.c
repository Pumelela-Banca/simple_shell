# include "main.h"

/**
 * removespace - function to remove space
 *
 * @s: string input
 *
 * Return: string
 */

char *removespace(char *s)
{
	char *tmp = s;

	while (*tmp == ' ')
		tmp++;
	return (_strdup(tmp));
}

/**
 * get_input - function to get input (non- interactive)
 * Return: buffer
 */
char **get_input(void)
{
	int z = 0, k = 0, j = 0;
	char *buff = NULL, *tmp = NULL, **lines = NULL;
	size_t n = 1024;

	lines = malloc(20 * sizeof(char *));
	if (lines == NULL)
	{
		perror("Error: can't allocate memory");
		_free(evar_);
		exit(1);
	}
	do {
		buff = malloc(n * sizeof(char));
		if (buff == NULL)
		{
			perror("Error: can't allocate memory");
			_free(evar_);
			while (k < j)
			{
				free(lines[j]);
				j++;
			}
			free(lines);
			exit(1);
		}
		z = getline(&buff, &n, stdin);
		if (z == -1)
		{
			free(buff);
			break;
		}
		tmp = removespace(buff);
		free(buff);
		buff = tmp;
		lines[j] = _strdup(buff);
		free(buff);
		j++;
	} while (z != -1);
	lines[j] = NULL;
	return (lines);
}
