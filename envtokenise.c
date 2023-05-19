#include "main.h"

/**
 * envtokenise - separates enviromental variables
 *
 * Return: list of directories
 */

char **envtokenise(void)
{
        char **new = NULL;
	int j = 0, k = 0;

	while (environ[j] != NULL)
	{
		j++;
	}
	j++;
	new = malloc(j * sizeof(char *));
	if (new == NULL)
	{
		perror("Error");
		return (NULL);
	}
	j = 0;
	while (environ[j] != NULL)
	{
		new[j] = _strdup(environ[j]);
		if (new[j] == NULL)
		{
			for (k = 0; k < j; k++)
			{
				free(new[k]);
			}
			free(new);
			return (NULL);
		}
		j++;
	}
	new[j] = NULL;
	return (new);
}
