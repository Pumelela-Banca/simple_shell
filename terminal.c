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
	int j = 0, count = 0;
	char **cmds = NULL;
	char *buff = NULL, *real = NULL, *tmp;

	do
	{
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
			_cd(envp, cmds);
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
		else if ((_strcmp(cmds[0], "echo") == 0) && (cmds[1][0] == '$'))
		{
			_env_var_print(envp, cmds);
			continue;
		}
		else
		{
			real = checkdir("/", cmds[0]);
			if (real == NULL)
			{
				print_error(count, argv, cmds);
				free(real);
				_free(cmds);
				continue;
			}
			tmp = cmds[0];
			cmds[0] = _strdup(real);
			free(tmp);
			file_exec(envp, cmds);
			continue;
		}
		j++;
	} while (j < 10);
}
