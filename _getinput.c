# include "main.h"
/**
 * getpath - function
 * @cmd: cmd
 * @envp: envp
 * Return: buff
 */
char *getpath(char *cmd, char *envp[])
{

	char *buff = NULL, *token = NULL;
	char *path = _getenv("PATH");

	(void)envp;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	buff = malloc((_strlen("/usr") + _strlen(cmd) + 2) * sizeof(char));
	if (buff == NULL)
	{
		perror("Error: can't allocate buffer space");
		exit(1);
	}
	_strcpy(buff, "/usr");
	if (cmd[0] != '/')
		_strcat(buff, "/");
	_strcat(buff, cmd);
	if (access(buff, X_OK) == 0)
		return (buff);
	free(buff);
	token = strtok(path, ":");
	do {
		buff = malloc((_strlen(token) + _strlen(cmd) + 2) * sizeof(char));
		if (buff == NULL)
		{
			perror("Error: can't allocate buffer space");
			exit(1);
		}
		_strcpy(buff, token);
		_strcat(buff, "/");
		_strcat(buff, cmd);
		if (access(buff, X_OK) == 0)
			return (buff);
		token = strtok(NULL, ":");
	} while (token != NULL);
	perror("Error");
	return (NULL);
}

