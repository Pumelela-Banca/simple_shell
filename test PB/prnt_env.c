#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
/**
 * prnt_env - uses environ to print environment
 *
 * Return: void
 */

extern char **environ;

void print_env(char **a)
{
	
	int i = 0;
	while (a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
}

void print_env(char **a);
int main(void)
{
	print_env(environ);
}
