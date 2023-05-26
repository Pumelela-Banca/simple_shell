#include "main.h"

/**
 * lines_split - function to tokenise buffer input
 * @buff: buffer input
 * Return: pointer to the array of string tokens
 */
char **lines_split(char *buff)
{
	char *delim = ";";
	char *token = NULL;
	int i = 0, j = 0;
	char **cmds = malloc(10 * sizeof(char *));

	token = strtok(buff, delim);
	do {
		cmds[i] = _strdup(token);
		if (cmds[i] == NULL)
		{
			while (j < i)
			{
				free(cmds[j]);
				j++;
			}
			free(cmds);
			exit(1);
		}
		token = strtok(NULL, delim);
		i++;
	} while (token != NULL);

	cmds[i] = NULL;
	free(buff);
	return (cmds);
}
/**
 * terminal - controls interactive mode  in shell
 *
 * @argv: command arguments
 *
 * Return: void
 */
void terminal(char *argv[])
{
	int count = 0, i = 0, k = 0, z = 0, *ptr = &count;
	char **cmds = NULL, *line = NULL, *buff = NULL;
	ff_t built[] = {{"exit", _exit_}, {"cd", _cd}, {"env", _env},
		{"setenv", _setenv}, {"unsetenv", _unsetenv}, {NULL, NULL}};

	do {
		buff = _shellprint();
		lines = lines_split(buff);
		count++;
		z = 0;
		while (lines[z] != NULL)
		{
			line = lines[z];
			if (filter(line) == 1)
			{
				z++;
				free(line);
				continue;
			}
			cmds = tokenise(line);
			i = 0;
			do {
				if (_strcmp(cmds[0], built[i].name) == 0)
				{
					built[i].fun(cmds);
					k++;
				}
				i++;
			} while (built[i].name != NULL);
			if (k != 0)
				k = 0;
			else if (_strcmp(cmds[0], "which") == 0)
				_which(cmds);
			else
				file_exec(cmds, argv, ptr);
			z++;
		}
		_free(lines);
		continue;
	} while (1);
}
