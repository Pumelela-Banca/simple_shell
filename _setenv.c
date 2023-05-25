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

	char **tmp = NULL;
	char *envr = NULL;

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
