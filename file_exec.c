# include "main.h"

/**
 *  file_exec - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void file_exec(char *envp[], char *cmds[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		_free(cmds);
		exit(1);
	}
	else if (pid == 0)
	{
		execfile(cmds, envp);
		perror("execve failed");
		_free(cmds);
		exit(1);
	}
	else
	{
		wait(NULL);
		_free(cmds);
	}
}
