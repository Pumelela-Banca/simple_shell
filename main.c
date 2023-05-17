#include "main.h"

/**
 * main - entry point of shell
 *
 * @argc: number of arguments
 * @argv: arguments
 * @envp: enviromental variables
 *
 * Return: always return 0
 */

int main(int argc, char *argv[], char *envp[])
{
	int j = 0;
	char **cmds = NULL;
	char *buff = NULL;
	char *term = "xterm";

	setenv("TERM", term, 1);
	do
	{
		buff = _shellprint();
		cmds = tokenise(buff);
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
			file_exec(envp, cmds);
			continue;
		}
		j++;
	} while (j < 10);
	return (0);
}
