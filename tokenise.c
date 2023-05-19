# include "main.h"
/**
 * tokenise - function to tokenise buffer input
 * @buff: buffer input
 * Return: pointer to the array of string tokens
 */
char **tokenise(char *buff)
{

	char *path = NULL;
	char *delim = " ";
	char *token = NULL;
	int i = 0, j = 0;
	char **cmds = malloc(10 * sizeof(char *));

	token = strtok(buff, delim);
	do {
		cmds[i] = _strdup(token);
		if (cmds[i] == NULL)
		{
			while (j < i)
			{
				free(cmds[j]);
				j++;
			}
			free(cmds);
			exit(1);
		}
		token = strtok(NULL, delim);
		i++;
	} while (token != NULL);

	cmds[i] = NULL;
	free(buff);
	return (cmds);
}
