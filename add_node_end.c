#include "shell.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: A pointer to the previous node pointer
 * @dir: list_t string (malloc'ed string)
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new_node, *temp;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	temp = *head;

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;

		return (new_node);
	}

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_node;

	return (new_node);
}
