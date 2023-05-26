#include "main.h"

/**
 * execfile - calls execve function
 *
 * @cmds: commands
 *
 * Return: void
 */
void execfile(char *cmds[])
{
	execve(cmds[0], cmds, evar_);
}
