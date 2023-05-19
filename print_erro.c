#include "main.h"

/**
 * print_error - prints custom error message
 *
 * @err_msg: error message
 *
 * Return: void
 */

void print_error(int num_cy, char *argv[], char *cmds[])
{
	printstr(argv[0]);
	printstr(": ");
	print_num(num_cy);
	printstr(": ");
	printstr(cmds[0]);
	printstr(": ");
	printstir("not found");
	printstr("\n");
}
