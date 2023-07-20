#include "shell.h"

/**
 * handle_builtin - handles builtins if implemented
 * @command: pointer to command to compare
 * @buf: passed buf to free
 * @env: to printenv
 */
void handle_builtin(char **command, char *buf, char **env)
{
	if (_strcmp(command[0], "exit") == 0)
		_exit_(command, buf);
	if (_strcmp(command[0], "env") == 0 || _strcmp(command[0], "printenv") == 0)
		_printenv(env);
}
