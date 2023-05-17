#include "main.h"

/**
 * print_error - prints custom error message
 *
 * @err_msg: error message
 *
 * Return: void
 */

void print_error(cals_t *env_info, char *err_msg)
{
	printstr(env_info->fname);
	printstr(": ");
	print_num(env_info->nm_cls);
	printstr(": ");
	printstr(env_info->sh_arg);
	printstr(": ");
	printstir(err_msg);
	printstr("\n");
}
