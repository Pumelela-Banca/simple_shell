# include "main.h"
/**
 *  _clear - clear
 *  @cmds: *cmds[]
 */
void _clear(char *cmds[])
{
	printstr("\033[2J\033[H");
	_free(cmds);
}
