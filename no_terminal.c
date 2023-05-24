#include "main.h"

/**
 * no_terminal - runs hsh code in a pipe situation
 *
 * @argv: commands
 *
 * Return: void
 */

void no_terminal(char **argv)
{
	char *buff = NULL, *path;
	char **cmds = NULL;
	int count = 1, *ptr = &count, i, k;
	ff_t built[] = {{"exit", _exit_}, {"clear", _clear}, {"cd", _cd},
		{"env", _env}, {"setenv", _setenv}, {"unsetenv", _unsetenv}, {NULL, NULL}};

	if (argv[1])
	{
		path = checkdir("/", argv[1]);
		if (path)
			buff = readfile(path);
	}
	else
		buff = get_input();
	cmds = tokenise(buff);
	i = 0;
	while (built[i].name != NULL)
	{
		if (_strcmp(cmds[0], built[i].name) == 0)
		{
			built[i].fun(cmds);
			k++;
		}
		i++;
	}
	if (k != 0)
		k = 0;
	else if (_strcmp(cmds[0], "which") == 0)
	{
		if (_which(cmds) == 1)
		{
			_free(evar_);
			exit(1);
		}
	}
	else if ((_strcmp(cmds[0], "echo") == 0) && (cmds[1][0] == '$'))
		_env_var_print(cmds);
	else
	{
		if (file_exec(cmds, argv, ptr) == 1)
		{
			_free(evar_);
			exit(127);
		}
	}
	_free(evar_);
	exit(0);
}
