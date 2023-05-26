#include "main.h"

/**
 *  _cd_home - cd
 *  @cmds: *cmds[]
 */
void _cd_home(char *cmds[])
{

	char *buff = NULL, **new = NULL;
	char *tmp = NULL, *tmp1 = NULL;
	(void)cmds;

	tmp = _getenv("HOME");
	tmp1 = _getenv("PWD");

	if (chdir(tmp) != 0)
	{

		printstr("invalid HOME directory");
		fflush(stdout);
		perror("");
		free(tmp);
		return;
	}
	else
	{
		buff = malloc(1024 * sizeof(char));
		_strcpy(buff, "setenv ");
		_strcat(buff, "PWD ");
		_strcat(buff, tmp);
		free(tmp);
		new = tokenise(buff);
		free(buff);
		_setenv(new);

		buff = malloc(1024 * sizeof(char));
		_strcpy(buff, "setenv ");
		_strcat(buff, "OLDPWD ");
		_strcat(buff, tmp1);
		new = tokenise(buff);
		free(buff);
		_setenv(new);
		free(tmp1);
	}
}

/**
 *  _cd_dir - cd DIRECTORY
 *  @cmds: *cmds[]
 */
void _cd_dir(char *cmds[])
{
	char *buff = NULL, **new = NULL;
	char *tmp = NULL;
	char cwd[1024];

	tmp = _getenv("PWD");

	if (chdir(cmds[1]) != 0)
	{
		printf("error");
		fflush(stdout);
		perror("");
		free(tmp);
		return;
	}
	if (getcwd(cwd, 1024) == NULL)
	{
		perror("getcwd() error");
		free(buff);
		return;
	}
	buff = malloc(1024 * sizeof(char));
	_strcpy(buff, "setenv ");
	_strcat(buff, "PWD ");
	_strcat(buff, cwd);
	new = tokenise(buff);
	free(buff);
	_setenv(new);

	buff = malloc(1024 * sizeof(char));
	_strcpy(buff, "setenv ");
	_strcat(buff, "OLDPWD ");
	_strcat(buff, tmp);
	new = tokenise(buff);
	free(buff);
	_setenv(new);
	free(tmp);
}
/**
 *  _cd_prev - go back to the previous folder
 *  @cmds: *cmds[]
 */
void _cd_prev(char *cmds[])
{
	char *buff = NULL, **new = NULL;
	char *tmp = NULL, *old = NULL;
	char cwd[1024];

	(void)cmds;

	tmp = _getenv("PWD");
	old = _getenv("OLDPWD");

	if (chdir(old) != 0)
	{
		printf("error");
		fflush(stdout);
		perror("");
		free(old);
		return;
	}
	free(old);
	if (getcwd(cwd, 1024) == NULL)
	{
		perror("getcwd() error");
		free(buff);
		return;
	}
	buff = malloc(1024 * sizeof(char));
	_strcpy(buff, "setenv ");
	_strcat(buff, "PWD ");
	_strcat(buff, cwd);
	new = tokenise(buff);
	free(buff);
	_setenv(new);

	buff = malloc(1024 * sizeof(char));
	_strcpy(buff, "setenv ");
	_strcat(buff, "OLDPWD ");
	_strcat(buff, tmp);
	new = tokenise(buff);
	free(buff);
	_setenv(new);
	free(tmp);
}
/**
 *  _cd - change directory
 *  @cmds: *cmds[]
 */
void _cd(char *cmds[])
{
	if (cmds[1] == NULL)
	{
		_cd_home(cmds);
	}
	if (cmds[1] != NULL)
	{
		if (_strcmp(cmds[1], "-") == 0)
		{
			_cd_prev(cmds);
		}
		else
		{
			_cd_dir(cmds);
		}
	}
	_free(cmds);
}
