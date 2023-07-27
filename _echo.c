#include "shell.h"

/**
 * _echo - mimics echo
 * @command: pointer to string to be printed
 */
void _echo(char **command)
{
	int len = _strlen(command[1]), i;

	if (command[1][0] == '"' && command[1][len - 1] == '"')
	{
		/* "cat" */
		for (i = 1; command[1][i] != '"'; i++)
			_putchar(command[1][i]);
	}
	else
		write(STDOUT_FILENO, command[1], _strlen(command[1]));
	_putchar('\n');
}
