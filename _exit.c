#include "shell.h"

/**
 * _exit_ - terminates the calling process
 * @command: A pointer to an array of character pointers  passed to the program
 * @buf: A temporary buffer used by the program
 */
void _exit_(char **command, char *buf)
{
	unsigned int status = 0;
	char *exit_status;

	if (command[1])
	{
		exit_status = command[1];
		status = atoi(exit_status);
	}

	free(buf);
	_free(command);
	_exit(status);
}
