#include "shell.h"

/***/
char *make_full_path(char *dir, char *command)
{
	size_t size, i, j;
	char *full_path;

	size = _strlen(dir) + _strlen(command) + 2;
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
	char *value, *dir, *full_path = NULL, *command_cpy;

	value = _strdup(_getenv("PATH"));

	dir = strtok(value, ":");
	while (dir)
	{
		full_path = make_full_path(dir, *command);
		if (access(full_path, F_OK) == 0)
		{
			command_cpy = *command;
			*command = full_path;
			free(value);
			free(command_cpy);
			return;
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(value);
}
