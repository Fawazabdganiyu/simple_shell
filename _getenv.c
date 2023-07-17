#include "shell.h"

/**
 * _getenv - gets an environment variable
 * @name: The key in the environment to get its value
 *
 * Return: A pointer to the beginning of the value
 */
char *_getenv(const char *name)
{
	char **env = environ;
	unsigned int key_len;

	if (name == NULL)
		return (NULL);

	key_len = strlen(name);
	for (; *env; env++)
	{
		if ((strncmp(*env, name, key_len) == 0) && ((*env)[key_len] == '='))
			return (*env + key_len + 1);
	}

	return (NULL);
}
