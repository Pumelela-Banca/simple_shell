#include "main.h"

/**
 * terminal - controls interactive mode  in shell
 *
 * @argv: command arguments
 *
 * Return: void
 */
void terminal(char *argv[])
{
	int count = 0, i = 0, k = 0, *ptr = &count;
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
		i = 0;
		while (built[i].name != NULL)
		{
			:w
		if (k != 0)
			k = 0;
		else if (_strcmp(cmds[0], "which") == 0)
			_which(cmds);
		else if ((_strcmp(cmds[0], "echo") == 0) &&
				(cmds[1][0] == '$'))
			_env_var_print(cmds);
		else
			file_exec(cmds, argv, ptr);
		continue;
	} while (1);
}
