#include "shell.h"

/**
 * _error - displays error message and exit with appropriate satus
 * @program: The first argument received from the main function
 * @command: A pointer to an array of malloc'ed arguments received from stdin
 * @buf: The buffer used for stdin commands
 * @n: A pointer to the count of error encountered
 */
void _error(char *program, char **command, char *buf, unsigned int *n)
{
	(*n)++;
	write(STDERR_FILENO, program, _strlen(program));
	write(STDERR_FILENO, ": ", 2);
	put_u_int(*n);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, *command, _strlen(*command));
	write(STDERR_FILENO, ": not found\n", 12);

	if (!isatty(STDIN_FILENO))
	{
		free(buf);
		_free(command);
		exit(127);
	}
}
