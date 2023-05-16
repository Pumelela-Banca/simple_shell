# include "main.h"
/**
 *  _which - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void _which(char *envp[], char *cmds[])
{
	int i = 1;
	char *path = NULL;

	while (cmds[i] != NULL)
	{
		path = getpath(cmds[i], envp);
		printf("%s\n", path);
		free(path);
		i++;
	}
	_free(cmds);
}
