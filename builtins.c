#include "shell.h"

int check_builtin(char **command);
void _printenv(char **env);
void _exit_cp(char **command, char *buf, char **sep_arr);
void handle_builtin(char **command, char *buf, char **env, char ** sep_arr);

/**
 * check_builtin - checks if a command is part of
 * implemented builtins
 *
 * @command: pointer to command to check for
 * Return: 0 if builtin | -1 otherwise
 */
int check_builtin(char **command)
{
	char *builtins[] = {"exit", "env", "printenv", "setenv", "cd",
		"unsetenv", NULL};
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
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}

/**
 * _exit_cp - terminates the calling process
 * @command: A pointer to an array of character pointers  passed to the program
 * @buf: A temporary buffer used by the program
 */
void _exit_cp(char **command, char *buf, char **sep_arr)
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
	_free(sep_arr);
	_exit(status);
}

/**
 * handle_builtin - handles builtins if implemented
 * @command: pointer to command to compare
 * @buf: passed buf to free
 * @env: to printenv
 */
void handle_builtin(char **command, char *buf, char **env, char **sep_arr)
{
	int set_retval = 0;

	if (_strcmp(command[0], "exit") == 0)
		_exit_cp(command, buf, sep_arr);

	if (_strcmp(command[0], "cd") == 0)
		cd(env, command[1]);

	if (_strcmp(command[0], "env") == 0 ||
			_strcmp(command[0], "printenv") == 0)
		_printenv(env);

	if (_strcmp(command[0], "setenv") == 0)
	{
		if (command[1] && command[2] && command[3])
			set_retval = _setenv(env, command[1], command[2], _atoi(command[3]));
		if (set_retval == -1)
			write(STDERR_FILENO, "Error: setenv failed\n", 21);
	}

	if (_strcmp(command[0], "unsetenv") == 0)
	{
		if (command[1])
			set_retval = _unsetenv(env, command[1]);
		if (set_retval == -1)
			write(STDERR_FILENO, "Error: unsetenv failed\n", 23);
	}
}
