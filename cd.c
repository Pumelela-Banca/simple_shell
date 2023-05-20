#include "main.h"
/**
 *  _cd - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 *  @argv: argv
 */
void _cd(char *envp[], char *argv[], char *cmds[])
{
	(void)envp;
	(void)argv;
	if (chdir(cmds[1]) != 0)
	{
		_free(cmds);
		perror("change directory failed");
	}
	_free(cmds);
}
