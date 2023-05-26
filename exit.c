# include "main.h"

/**
 *  _exit_ - exit
 *  @cmds: *cmds[][]
 */
void _exit_(char *cmds[])
{
	int i;

	if (cmds[1] == NULL)
	{
		_free(cmds);
		_free(commands);
		_free2();
		exit(0);
	}
	else
	{
		i = _atoi(cmds[1]);
		_free(cmds);
		 _free(commands);
		_free2();
		exit(i);
	}
}
