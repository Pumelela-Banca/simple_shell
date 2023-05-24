#include "main.h"

/**
 * terminal - controls interactive mode  in shell
 *
 * @argv: command arguments
 * @envp: environment variables
 *
 * Return: void
 */
void terminal(char *argv[])
{
	int j = 0, count = 0, *ptr = &count;
	char **cmds = NULL;
	char *buff = NULL;

	do {
		buff = _shellprint();
		cmds = tokenise(buff);
		count++;
		if (_strcmp(cmds[0], "exit") == 0)
			_exit_(cmds);
		else if (_strcmp(cmds[0], "clear") == 0)
		{
			_clear(cmds);
			continue;
		}
		else if (_strcmp(cmds[0], "cd") == 0)
		{
			_cd(cmds);
			continue;
		}
		else if (_strcmp(cmds[0], "which") == 0)
		{
			_which(cmds);
			continue;
		}
		else if (_strcmp(cmds[0], "env") == 0)
		{
			_env(cmds);
			continue;
		}
		else if (_strcmp(cmds[0], "setenv") == 0)
		{
			_setenv(cmds);
			continue;
		}
		else if (_strcmp(cmds[0], "unsetenv") == 0)
		{
			_unsetenv(cmds);
			continue;
		}
		else if ((_strcmp(cmds[0], "echo") == 0) &&
				(cmds[1][0] == '$'))
		{
			_env_var_print(cmds);
			continue;
		}
		else
		{
			file_exec(cmds, argv, ptr);
			continue;
		}
		j++;
	} while (j < 10);
}
