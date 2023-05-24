# include "main.h"
/**
 * getpath - function
 *
 * @cmd: cmd
 *
 * Return: buff
 */

char *getpath(char *cmd)
{
	char *buff = NULL, *token = NULL;
	char *path = NULL;

	if (access(cmd, X_OK) == 0)
	{
		buff = _strdup(cmd);
		return (buff);
	}
	path = _getenv("PATH");
	token = strtok(path, ":");
	do {
		buff = malloc((_strlen(token) + _strlen(cmd) + 2) * sizeof(char));
		if (buff == NULL)
		{
			free(path);
			perror("Error: can't allocate buffer space");
			_free(evar_);
			exit(1);
		}
		_strcpy(buff, token);
		_strcat(buff, "/");
		_strcat(buff, cmd);
		if (access(buff, X_OK) == 0)
		{
			free(path);
			return (buff);
		}
		else
		{
			free(buff);
			token = strtok(NULL, ":");
		}
	} while (token != NULL);
	free(path);
	return (NULL);
}
