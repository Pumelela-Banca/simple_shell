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

	while (evar_[i] != NULL)
	{
		j = 0;
        while (evar_[i][j] != '=')
        {
		token[j] = evar_[i][j];
		j++;
	}
	token[j] = '\0';
	if (_strcmp(token, cmds[1]) == 0)
	{
		free(evar_[i]);
		evar_[i] = malloc(_strlen(cmds[1]) + _strlen(cmds[2]) + 2);
		if (evar_[i] == NULL)
		{
			_free(evar_);
			perror("can't allocate memory");
			exit(1);
		}
		_strcpy(evar_[i], cmds[1]);
		_strcat(evar_[i], "=");
		_strcat(evar_[i], cmds[2]);
		break;
	}
	i++;
	}
}
