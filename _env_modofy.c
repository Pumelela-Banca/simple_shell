#include "main.h"

/**
 * _env_modify - modyfy environment
 *
 * @cmds: commands
 *
 * Return: void
 */

void _env_modify(char *cmds[])
{
	char token[1024];
	int i = 0, j = 0;
	char *tmp = NULL;

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
		free(evar[i]);
		evar[i] = malloc(strlen(cmds[1]) + strlen(cmds[2]) + 2);
		if (evar[i] == NULL)
		{
			_free(evar);
			perror("can't allocate memory");
			exit(1);
		}
		_strcpy(evar[i], cmds[1]);
		_strcat(evar[i], "=");
		_strcat(evar[i], cmds[2]);
		break;
	}
	i++;
	}
}
