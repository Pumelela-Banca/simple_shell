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
	int count = 1, *ptr = &count;

	if (argv[1])
	{
		path = checkdir("/", argv[1]);
		if (path)
			buff = readfile(path);
	}
	else
		buff = get_input();
	cmds = tokenise(buff);
	if (_strcmp(cmds[0], "exit") == 0)
		_exit_(cmds);
	else if (_strcmp(cmds[0], "cd") == 0)
		_cd(cmds);
	else if (_strcmp(cmds[0], "which") == 0)
		_which(cmds);
	else if (_strcmp(cmds[0], "env") == 0)
		_env(cmds);
	else if (_strcmp(cmds[0], "setenv") == 0)
		_setenv(cmds);
	else if (_strcmp(cmds[0], "unsetenv") == 0)
		_unsetenv(cmds);
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
