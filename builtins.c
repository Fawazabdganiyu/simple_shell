#include "shell.h"

int check_builtin(char **command);
void _printenv(char **env);
void _exit_cp(char **command, char *buf);
void handle_builtin(char **command, char *buf, char **env);

/**
 * check_builtin - checks if a command is part of
 * implemented builtins
 *
 * @command: pointer to command to check for
 * Return: 0 if builtin | -1 otherwise
 */
int check_builtin(char **command)
{
	char *builtins[] = {"exit", "env", "printenv", "cd", NULL};
	int i;

	for (i = 0; builtins[i]; i++)
		if (_strcmp(command[0], builtins[i]) == 0)
			return (0);
	return (-1);
}

/**
 * _printenv - prints the local processes environment
 * variable
 *
 * @env: environment variable
 */
void _printenv(char **env)
{
	(void)env;
/**
 *	int i;
 *
 *	for (i = 0; env[i] != NULL; i++)
 *	{
 *		printf("%s\n", env[i]);
 *	}
 */
}

/**
 * _exit_cp() - terminates the calling process
 * @command: A pointer to an array of character pointers  passed to the program
 * @buf: A temporary buffer used by the program
 */
void _exit_cp(char **command, char *buf)
{
	unsigned int status = 0;
	char *exit_status;

	if (command[1])
	{
		exit_status = command[1];
		status = _atoi(exit_status);
	}

	free(buf);
	_free(command);
	_exit(status);
}

/**
 * handle_builtin - handles builtins if implemented
 * @command: pointer to command to compare
 * @buf: passed buf to free
 * @env: to printenv
 */
void handle_builtin(char **command, char *buf, char **env)
{
	(void)env;
	if (_strcmp(command[0], "exit") == 0)
		_exit_cp(command, buf);

	if (_strcmp(command[0], "cd") == 0)
		cd(command[1]);

/**	if (_strcmp(command[0], "env") == 0 ||
 *	_strcmp(command[0], "printenv") == 0)
 *		_printenv(env);
 */
}
