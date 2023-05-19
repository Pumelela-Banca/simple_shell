#include "main.h"

/**
 * main - entry point of shell
 *
 * @argc: number of arguments
 * @argv: arguments
 * @envp: enviromental variables
 *
 * Return: always return 0
 */

int main(int argc, char *argv[], char *envp[])
{

	(void)argc;

	if (argc == 2 || isatty(STDIN_FILENO) == 0)
		no_terminal(argv, envp);
	else
		terminal(argv, envp);
	return (0);
}
