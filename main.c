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

char **evar_;
char **lines;
int main(int argc, char *argv[], char *envp[])
{
	evar_ = envtokenise(environ);
	(void)evar_;
	(void)envp;

	/*char evar_ = envtokenise(environ);*/
	if (argc == 2 || (isatty(STDIN_FILENO) == 0))
		no_terminal(argv);
	else
		terminal(argv);
	return (0);
}
