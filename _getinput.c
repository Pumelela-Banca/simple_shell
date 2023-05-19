# include "main.h"
/**
 * getpath - function
 * @cmd: cmd
 * @envp: envp
 * Return: buff
 */
char *getpath(char *cmd, char *envp[])
{
	static char buff[102400];
	char *token = NULL;
	char *path = NULL;


	if (access(cmd, X_OK) == 0)
	{
		return (_strdup(cmd));
	}

	path = _getenv("PATH");
	token = strtok(path, ":");

	do {
		_strcpy(buff, token);
		_strcat(buff, "/");
		_strcat(buff, cmd);

		if (access(buff, X_OK) == 0)
		{
			free(path);
			return (_strdup(buff));
		}
		token = strtok(NULL, ":");
	} while (token != NULL);

	free(path);
	return (NULL);
}
