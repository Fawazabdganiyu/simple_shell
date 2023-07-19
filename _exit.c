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
		status = _atoi(exit_status);
	}

	free(buf);
	_free(command);
	_exit(status);
}

/***/
void _error(char *program, char **command, char *buf, unsigned int *n)
{
	char *num;

	(*n)++;
	num = uint_to_str(*n);
	if (num)
	write(STDERR_FILENO, program, _strlen(program));
	write(STDERR_FILENO, ": ", 2);
	if (num)
		write(STDERR_FILENO, num, 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, *command, _strlen(*command));
	write(STDERR_FILENO, ": not found\n", 12);

	if (!isatty(STDIN_FILENO))
	{
		free(num);
		free(buf);
		_free(command);
		exit(127);
	}
	free(num);
}
