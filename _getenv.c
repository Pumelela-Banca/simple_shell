# include "main.h"

/**
 * _getenv - function
 * @name: variable name
 * Return: value
 */

char *_getenv(char *name)
{

	char *tmp = NULL;
	char token[1024];
	char *new  = NULL;

	int i = 0, j = 0;

	while (evar_[i] != NULL)
	{
		j = 0;
		while (evar_[i][j] != '=')
		{
			token[j] = evar_[i][j];
			j++;
		}
		token[j] = '\0';
		if (_strcmp(token, name) == 0)
		{
			j++;
			tmp = &evar_[i][j];
			new = _strdup(tmp);
			return (new);
		}
		i++;
	}
	return (NULL);
}
