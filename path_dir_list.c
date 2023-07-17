#include "shell.h"

/***/
list_t *path_dir_list(void)
{
	char *value, *token;
	list_t *head = NULL;

	value = _getenv("PATH");

	token = strtok(value, ":");
	while (token)
	{
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/***/
char *make_full_path(char *dir, char *command)
{
	size_t size, i, j;
	char *full_path;

	size = strlen(dir) + strlen(command) + 2;
	full_path = malloc(sizeof(char) * size);
	if (!full_path)
		return (NULL);
	/* Concatenate the strings */
	for (i = 0; dir[i]; i++)
		full_path[i] = dir[i];

	full_path[i++] = '/';

	for (j = 0; command[j]; j++)
		full_path[i + j] = command[j];

	full_path[i + j] = '\0';

	return (full_path);
}

/***/
void search_path(char **command)
{
	char *full_path;
	list_t *head, *h;
	struct stat st;

	head = path_dir_list();
	h = head;
	while (h)
	{
		full_path = make_full_path(h->str, command[0]);
/*		printf("head->str: %s\n", h->str);
		printf("full_path: %s\n", full_path);
*/		if (stat(full_path, &st) == 0)
		{
			command[0] = full_path;
		}
/*		printf("cyommand[0]: %s\n", command[0]);
*/		h = h->next;
	}

	free_list(head);
}
