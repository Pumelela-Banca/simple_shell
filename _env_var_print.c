# include "main.h"
/**
 *  _env_var_print - exit
 *  @cmds: *cmds[][]
 */
void _env_var_print(char *cmds[])
{
	int i = 1;
	char *envvar = NULL;
	char *tmp = NULL;

	while (cmds[i] != NULL)
	{
		envvar = cmds[i];
		envvar++;
		tmp = _getenv(envvar);
		printstr(tmp);
		printstr(" ");
		free(tmp);
		i++;
	}
	printstr("\n");
	_free(cmds);
}
