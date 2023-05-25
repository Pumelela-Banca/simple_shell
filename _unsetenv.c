# include "main.h"

/**
 * _unsetenv - function delete a variable
 * @cmds: input
 */

void _unsetenv(char *cmds[])
{

	char *envr = _getenv(cmds[1]);
	char **tmp = NULL;

	if (envr == NULL)
	{
		perror("variable does not exist");
		_free(cmds);
	}
	else
	{
		tmp = evar_;
		evar_ = _env_delete(cmds);
		_free(tmp);
		_free(cmds);
		free(envr);
	}
}
