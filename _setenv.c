#include "main.h"

/**
 * _setenv - sets enviroment variable
 *
 * @cmds: commands
 *
 * Return: void
 */

void _setenv(char *cmds[])
{
	int i = 0, j = 0, k = 0;
	char **new = NULL;
	char **tmp = NULL;
	char token[1024];
	char *envr = NULL;

	while (cmds[i] != NULL)
	{
		i++;
	}
	if (i != 3)
	{
		_free(cmds);
		perror("exess arguments on setenv");
		return;
	}
	envr = _getenv(cmds[1]);
	if (envr == NULL)
	{
		tmp = evar;
		evar = _envset(cmds);
		_free(tmp);
		_free(cmds);
	}
	else if (envr != NULL)
	{
		_env_modify(cmds);
		free(envr);
		_free(cmds);
	}
}
