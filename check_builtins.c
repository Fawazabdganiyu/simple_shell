#include "shell.h"

/**
 * check_builtin - checks if a command is part of
 * implemented builtins
 *
 * @command: pointer to command to check for
 * Return: 0 if builtin | -1 otherwise
 */
int check_builtin(char **command)
{
	char *builtins[] = {"exit", "env", "printenv", NULL};
	int i;

	for (i = 0; builtins[i]; i++)
		if (_strcmp(command[0], builtins[i]) == 0)
			return (0);
	return (-1);
}
