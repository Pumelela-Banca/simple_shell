#include "main.h"

/**
 * _envset - sets enviroment
 *
 * @cmds:commands
 *
 * Return: new environment
 */

char **_envset(char *cmds[])
{
	char **new = NULL;
	int j = 0, k = 0;

	while (evar[j] != NULL)
		j++;
	j = j + 2;
	new = malloc(j * sizeof(char *));
	if(new == NULL)
	{
		perror("Error");
		return (NULL);
	}
	j = 0;
	while (evar[j] != NULL)
	{
		new[j] = _strdup(evar[j]);
		if (new[j] == NULL)
			for (k = 0; k < j; k++)
				free(new[k]);
		free(new);
		return (NULL);
		j++;
	}
	new[j] = malloc(_strlen(cmds[1]) + _strlen(cmds[2]) + 2);
	if (new[j] == NULL)
	{
		for (k = 0; k < j; k++)
			free(new[k]);
		free(new);
		return (NULL);
	}
	_strcpy(new[j], cmds[1]);
	_strcat(new[j], "=");
	_strcat(new[j], cmds[2]);
	j++;
	new[j] = NULL;
	return (new);
}
