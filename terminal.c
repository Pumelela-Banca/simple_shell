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
	int j = 0, count = 0, i = 0, k = 0, *ptr = &count;
	char **cmds = NULL;
	char *buff = NULL;
	ff_t built[] = {{"exit", _exit_}, {"clear", _clear}, {"cd", _cd}, 
		{"env", _env}, {"setenv", _setenv}, {"unsetenv", _unsetenv}, {NULL, NULL}};

	do {
		buff = _shellprint();
		if (buff[0] == '\n')
		{
			free(buff);
			continue;
		}
		cmds = tokenise(buff);
		count++;

		while (built[i]->name != NULL)
		{
			if (_strcmp(cmds[0], built[i]->name) == 0)
			{
				built[i]->fun(cmds);
				k++;
			}
			i++;
		}
		if (k != 0)
		{
			k = 0;
			continue;
		}
		/*if (_strcmp(cmds[0], "exit") == 0)
			_exit_(cmds);*/
		/*else if (_strcmp(cmds[0], "clear") == 0)
		{
			_clear(cmds);
			continue;
		}
		else if (_strcmp(cmds[0], "cd") == 0)
		{
			_cd(cmds);
			continue;
		}*/
		else if (_strcmp(cmds[0], "which") == 0)
		{
			_which(cmds);
			continue;
		}
		/*else if (_strcmp(cmds[0], "env") == 0)
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
		}*/
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
