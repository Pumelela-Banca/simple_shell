# include "main.h"
/**
 *  _clear - clear
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void _clear(char *envp[], char *cmds[])
{
	(void)envp;

	_free(cmds);
	printf("\033[2J\033[H");
}
