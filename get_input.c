# include "main.h"

/**
 * removespace: function to remove space;
 * @s: string input
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

char *get_input(void)
{
	int z;
	char *buff = NULL, *tmp = NULL;
	size_t n = 1024, i = 0;

	buff = malloc(n * sizeof(char));
	if (buff == NULL)
	{
		perror("Error: can't allocate memory");
		_free(evar_);
		exit(1);
	}
	z = getline(&buff, &n, stdin);
	if (z == -1)
	{
		free(buff);
		_free(evar_);
		exit(0);
	}
	else
	{
		tmp = removespace(buff);
		free(buff);
		buff = tmp;
		if (buff[0] == '\n')
		{
			_free(evar_);
			free(buff);
			exit(0);
		}
		while (buff[i] != '\0')
		{
			if (buff[i] == '\n')
			{
				buff[i] = '\0';
				break;
			}
			i++;
		}
	}
	return (buff);
}