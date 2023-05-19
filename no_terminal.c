#include "main.h"

/**
 * no_terminal - runs hsh code in a pipe situation
 *
 * @cmds: commands
 * @envp: environment variables
 *
 * Return: void
 */

void no_terminal(char **argv, char **envp)
{
	char *real = NULL;
	char *buff = NULL;
	char **cmds = NULL;
	char *path;
	size_t n = 1024;
	int i;

	if (argv[1])
	{
		path = checkdir("/", argv[1]);
		if (path)
			buff = readfile(path);
	}
	else
		buff = get_input();

	cmds = tokenise(buff);
	if (_strcmp(cmds[0], "exit") == 0)
		_exit_(envp, cmds);
	else if (_strcmp(cmds[0], "clear") == 0)
		_clear(envp, cmds);
	else if (_strcmp(cmds[0], "cd") == 0)
		_cd(envp, cmds);
	else if (_strcmp(cmds[0], "which") == 0)
		_which(envp, cmds);
	else if (_strcmp(cmds[0], "env") == 0)
		_env(envp, cmds);
	else if ((_strcmp(cmds[0], "echo") == 0) && (cmds[1][0] == '$'))
		_env_var_print(envp, cmds);
	else
	{
		real = getpath(cmds[0], envp);
		if (real == NULL)
		{
			print_error(1, argv, cmds);
			free(real);
			exit(127);
		}
		tmp = cmds[0];
		cmds[0] = strdup(real);
		free(tmp);
		free(real);
		file_exec(envp, cmds);
	}
}

/**
 * get_input - gets line from echo and removes \n
 *
 * Returns: buffer
 */

char *get_input(void)
{
	int z;
	char *buff = NULL;
	size_t n = 1024, i = 0;

	buff = malloc(n * sizeof(char));
	if (buff == NULL)
	{
		perror("Error: can't allocate memory");
		exit(1);
	}
	z = getline(&buff, &n, stdin);
	if (z == -1)
	{
		exit(0);
	}
	else if (z == 1)
		exit(0);
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			break;
		}
		i++;
	}
	return (buff);
}
