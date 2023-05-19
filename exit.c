# include "main.h"

/**
 *  _exit_ - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void _exit_(char *envp[], char *cmds[])
{
	(void)envp;

	_free(cmds);
	exit(0);
}
