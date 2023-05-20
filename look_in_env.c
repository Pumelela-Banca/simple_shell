# include "main.h"
/**
 * look_in_env - function to find path vaiable in env
 * @head: input head node of env list
 * @name: env variable name
 * Return: value
 */
char *look_in_env(_var *head, char *name)
{
	_var *tmp = head;
	char *ret = NULL;

	while (tmp != NULL)
	{
		if (_strcmp(name, tmp->name) == 0)
		{
			ret = strdup(tmp->value);
			free_list(head);
			return (ret);
		}
		tmp = tmp->next;
	}
	free_list(head);
	return (NULL);
}
