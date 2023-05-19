#include "main.h"
/**
 *  _cd - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void _cd(char *envp[], char *cmds[])
{
	(void)envp;
	if (chdir(cmds[1]) != 0)
	{
		_free(cmds);
		perror("change directory failed");
	}
	_free(cmds);
}
