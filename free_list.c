#include "main.h"

/**
 * free_list - frees sruct with enviromental vvariables
 *
 * @head: first node pointer
 *
 * Return: Void
 */

void free_list(_var *head)
{
	_var *ptr = NULL;

	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr->name);
		free(ptr->value);
		free(ptr);
	}
}
