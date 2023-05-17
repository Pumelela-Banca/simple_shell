#include "main.h"

/**
 * execfile - calls execve function
 *
 * @cmds: commands
 * @envp: envoroment ariables
 *
 * Return: void
 */

void execfile(char *cmds[], char *envp[])
{
	execve(cmds[0], cmds, envp);
}
