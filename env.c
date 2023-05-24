# include "main.h"
/**
 *  _env - print environmental variable list
 *  @cmds: *cmds[]
 */

void _env(char *cmds[])
{
	int i = 0;

	while (evar_[i] != NULL)
	{
		printstr(evar_[i]);
		printstr("\n");
		i++;
	}
	_free(cmds);
}
