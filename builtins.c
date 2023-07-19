#include "shell.h"

void handle_builtin(char **command, char *buf)
{
	if (_strcmp(command[0], "exit") == 0)
		_exit_(command, buf);
}
