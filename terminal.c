#include "main.h"

/**
 * terminal - controls interactive mode  in shell
 *
 * @argv: command arguments
 * @envp: environment variables
 *
 * Return: void
 */
void terminal(char *argv[], char *envp[])
{
	int j = 0, count = 0, *ptr = &count;
	char **cmds = NULL;
	char *buff = NULL;

	do {
		buff = _shellprint();
		cmds = tokenise(buff);
		count++;
		if (_strcmp(cmds[0], "exit") == 0)
			_exit_(envp, cmds);
		else if (_strcmp(cmds[0], "clear") == 0)
		{
			_clear(envp, cmds);
			continue;
		}
		else if (_strcmp(cmds[0], "cd") == 0)
		{
			_cd(envp, argv, cmds);
			continue;
		}
		else if (_strcmp(cmds[0], "which") == 0)
		{
			_which(envp, cmds);
			continue;
		}
		else if (_strcmp(cmds[0], "env") == 0)
		{
			_env(envp, cmds);
			continue;
		}
		else if ((_strcmp(cmds[0], "echo") == 0) &&
				(cmds[1][0] == '$'))
		{
			_env_var_print(envp, cmds);
			continue;
		}
		else
		{
			file_exec(envp, cmds, argv, ptr);
			continue;
		}
		j++;
	} while (j < 10);
}
