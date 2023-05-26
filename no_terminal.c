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
 * no_terminal - runs hsh code in a pipe situation
 *
 * @argv: commands
 *
 * Return: void
 */

void no_terminal(char **argv)
{
	char **lines = NULL, *line = NULL, **cmds = NULL;
	int count = 1, *ptr = &count, z = 0, p = 0;

	lines = get_input();
	do {
		line = lines[z];
		if (filter(line) == 1)
		{
			z++;
			free(line);
			continue;
		}
		cmds = tokenise(lines[z]);
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
			if (file_exec(cmds, argv, ptr) == 1)
				p++;
		z++;
	} while (lines[z] != NULL);
	_free(evar_);
	free(lines);
	if (p != 0)
		exit(127);
	exit(0);
}
