#include "shell.h"

void handle_builtin(char **command, char *buf, char **env)
{
	if (_strcmp(command[0], "exit") == 0)
		_exit_(command, buf);
	if (_strcmp(command[0], "env") == 0|| _strcmp(command[0], "printenv") == 0)
		_printenv(env);
}
