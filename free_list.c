#include "shell.h"

/**
 * free_list - free a list_t list
 * @head: The pointer to the head node of the list.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
