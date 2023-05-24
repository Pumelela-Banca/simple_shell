# include "main.h"

/**
 * _unsetenv - function delete a variable
 * @cmds: input
 */

void _unsetenv(char *cmds[])
{
	int i = 0;
	char *envr = _getenv(cmds[1]);
	char **tmp = NULL;

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
