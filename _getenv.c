# include "main.h"
/**
 * _getenv - function
 * @name: name of variable
 * Return: value
 */
char *_getenv(char *name)
{
	_var *head = NULL;
	char *token = NULL, **new = NULL, *ret = NULL;

	new = envtokenise();
	token = strtok(new[0], "=");

	head = malloc(sizeof(_var));
	if (head == NULL)
	{
		_free(new);
		return (NULL);
	}
	head->name = _strdup(token);
	token = strtok(NULL, "\0");
	head->value = _strdup(token);
	if (head->name == NULL || head->value == NULL)
	{
		_free(new);
		free_list(head);
		return (NULL);
	}
	listpopulate(head, new);

	if (head == NULL)
		return (NULL);

	ret = look_in_env(head, name);
	return (ret);
}
