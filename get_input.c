# include "main.h"

/**
 * removespace - function to remove space at the beginning
 * @s: input buffer
 * Return: buffer
 */ 
char *removespace(char *s)
{
	char buff[1024], *tmp = NULL;
	int i = 0, j = 0;
	
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
		{
			while (s[i] != '\0')
			{
				buff[j] = s[i];
				j++;
				i++;
			}
		}
		i++;
	}
	buff[j] = '\0';
	tmp = _strdup(buff);
	return (tmp);
}
/**
 * get_input - function to get input (non- interactive)
 * Return: buffer
 */

char *get_input(void)
{
	int z;
	char *buff = NULL;
	size_t n = 1024, i = 0;
	char *tmp = NULL;

	buff = malloc(n * sizeof(char));
	if (buff == NULL)
	{
		perror("Error: can't allocate memory");
		exit(1);
	}
	z = getline(&buff, &n, stdin);
	if (z == -1)
	{
		free(buff);
		free(evar_);
		exit(0);
	}
	else
	{
		tmp = removespace(buff);
		free(buff);
		buff = tmp;
		if (buff[0] == '\n')
		{
			free(evar_);
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
