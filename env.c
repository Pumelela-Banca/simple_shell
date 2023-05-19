# include "main.h"
/**
 *  _env - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void _env(char *envp[], char *cmds[])
{
	int i = 0;

	while (envp[i] != NULL)
	{
		printstr(envp[i]);
		_putchar('\n');
		i++;
	}
	_free(cmds);
}
