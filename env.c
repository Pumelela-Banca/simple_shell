# include "main.h"
/**
 *  _env - print environmental variable list
 *  @cmds: *cmds[]
 */

void _env(char *cmds[])
{
	int i = 0;

	while (evar[i] != NULL)
	{
		printstr(evar[i]);
		printstr("\n");
		i++;
	}
	_free(cmds);
}
