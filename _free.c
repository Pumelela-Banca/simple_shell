#include "main.h"

/**
 * _free - frees command line string
 *
 * @cmds: command line string
 *
 * Return: void
 */

void _free(char *cmds[])
{
	int i = 0;

	while (cmds[i] != NULL)
	{
		free(cmds[i]);
		i++;
	}
	free(cmds);
}
