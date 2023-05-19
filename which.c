# include "main.h"
/**
 * _which - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 *  Return: 1 on failure and 0 on success
 */
int _which(char *envp[], char *cmds[])
{
	int i = 1, j = 0;
	char *path = NULL;

	while (cmds[i] != NULL)
	{
		path = getpath(cmds[i], envp);
		if (path == NULL)
		{
			i++;
			j++;
			continue;
		}
		printstr(path);
		_putchar('\n');
		free(path);
		i++;
	}
	_free(cmds);

	if (j != 0)
		return (1);
	return (0);
}
