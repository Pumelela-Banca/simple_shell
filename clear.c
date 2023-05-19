# include "main.h"
/**
 *  _clear - clear
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void _clear(char *envp[], char *cmds[])
{
	(void)envp;

	printstr("\033[2J\033[H");
	_free(cmds);
}
