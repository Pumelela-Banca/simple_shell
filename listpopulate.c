# include "main.h"
/**
 * listpopulate - function to populate list
 * @head: head node
 * @new: array of strings
 */
void listpopulate(_var *head, char *new[])
{
	_var *tmp = NULL, *prev = NULL;
	char *token = NULL;
	int i = 1;

	tmp = head;
	do {
		prev = tmp;
		tmp = NULL;
		tmp =  malloc(sizeof(_var));
		if (tmp == NULL)
		{
			_free(new);
			free_list(head);
			return;
		}
		token = strtok(new[i], "=");
		tmp->name = _strdup(token);
		token = strtok(NULL, "\0");
		tmp->value = _strdup(token);
		if (tmp->name == NULL || tmp->value == NULL)
		{
			_free(new);
			free_list(head);
			free(tmp);
			return;
		}
		prev->next = tmp;
		i++;
	} while (new[i] != NULL);
	_free(new);
}
