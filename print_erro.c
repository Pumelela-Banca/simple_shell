#include "main.h"

/**
 * print_error - prints custom error message
 *
 * @num_cy: argument number
 * @argv: arguments
 * @cmds: local arguments
 *
 * Return: void
 */

void print_error(int *num_cy, char *argv[], char *cmds[])
{
	printstr(argv[0]);
	printstr(": ");
	print_num(num_cy);
	printstr(": ");
	printstr(cmds[0]);
	printstr(": ");
	printstr("not found");
	printstr("\n");
}
