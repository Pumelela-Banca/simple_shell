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
	int i = 0;
	char **tmp = NULL;
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
		tmp = evar_;
		evar_ = _envset(cmds);
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
