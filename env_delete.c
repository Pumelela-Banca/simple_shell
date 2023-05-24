# include "main.h"

/**
 * _env_delete - function
 * @cmds: input
 * Return: new env
 */

char **_env_delete(char *cmds[])
{
	char token[1024];
	char **new = NULL;
	int j = 0, k = 0, z = 0, i = 0;

	while (evar[j] != NULL)
		j++;
	new = malloc(j * sizeof(char *));
	if (new == NULL)
	{
		perror("can't allocate memory");
		return (NULL);
	}
	while (evar[i] != NULL)
	{
		j = 0;
		while (evar[i][j] != '=')
		{
			token[j] = evar[i][j];
			j++;
		}
		token[j] = '\0';
		if (_strcmp(token, cmds[1]) == 0)
		{
			i++;
			continue;
		}
		new[z] = _strdup(evar[i]);
		if (new[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(new[k]);
			free(new);
			perror("can't allocate memory");
			return (NULL);
		}
		i++;
		z++;
	}
	new[z] = NULL;
	return (new);
}
