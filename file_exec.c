# include "main.h"

/**
 *  file_exec - exit
 *  @cmds: *cmds[][]
 *  @argv: argv
 *  @count: count
 *  Return: int
 */

int file_exec(char *cmds[], char *argv[], int *count)
{
	char *real = NULL, *tmp = NULL;
	pid_t pid;

	real = getpath(cmds[0]);
	if (real == NULL)
	{
		print_error(count, argv, cmds);
		_free(cmds);
		return (1);
	}
	tmp = cmds[0];
	cmds[0] = _strdup(real);
	free(tmp);
	free(real);

	pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		_free(cmds);
		_free(evar_);
		exit(1);
	}
	else if (pid == 0)
	{
		execfile(cmds);
		perror("execve failed");
		_free(cmds);
		_free(evar_);
		exit(1);
	}
	else
	{
		wait(NULL);
		_free(cmds);
	}
	return (0);
}
