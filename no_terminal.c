#include "main.h"
/**
 * filter - funct
 * @line: input
 * Return: int
 */
int filter(char *line)
{
	int i = 0;

	if (line[0] == '\n')
	{
		return (1);
	}
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break;
		}
		i++;
	}
	return (0);
}
/**
 * _free2 - function to free 3 extern chars
 */
void _free2(void)
{
	_free(evar_);
	_free(lines);
}
/**
 * no_terminal - runs hsh code in a pipe situation
 *
 * @argv: commands
 *
 * Return: void
 */

void no_terminal(char **argv)
{
	char *line = NULL, **cmds = NULL;
	int count = 1, *ptr = &count, z = 0, k = 0;

	lines = get_input();
	do {
		line = lines[z];
		if (filter(line) == 1)
		{
			z++;
			continue;
		}
		commands = lines_split(line);
		k = 0;
		while (commands[k] != NULL)
		{
			rm_comments(commands[k]);
			cmds = tokenise(commands[k]);
			if (_strcmp(cmds[0], "exit") == 0)
				_exit_(cmds);
			else if (_strcmp(cmds[0], "cd") == 0)
				_cd(cmds);
			else if (_strcmp(cmds[0], "env") == 0)
				_env(cmds);
			else if (_strcmp(cmds[0], "setenv") == 0)
				_setenv(cmds);
			else if (_strcmp(cmds[0], "unsetenv") == 0)
				_unsetenv(cmds);
			else
				if (file_exec(cmds, argv, ptr) == 1)
				{
					_free2();
					_free(commands);
					exit(127);
				}
			k++;
		}
		_free(commands);
		z++;
	} while (lines[z] != NULL);
	_free2();
	exit(0);
}
