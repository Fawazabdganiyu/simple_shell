#include "shell.h"

/**
 * main - Entry point
 * @ac: Number of arguments passed to the program
 * @av: A pointer to an array of arguments passed to the program
 *
 * Description: Simple Shell (CLI)
 *
 * Return: 0 on sucsess
 */
int main(int ac, char **av)
{
	char *buf = NULL, **arr, *delim = " \n", **env = environ;
	size_t n = 0, i, retval;
	char *program;

	(void)ac;
	program = av[0];
	while (1)
	{
		_isatty();

		/* Parse the commands */
		if (getline(&buf, &n, stdin) == -1)
			break;

		arr = split_string(buf, delim);
		for (i = 0; arr[i]; i++)
			;

		retval = _fork(program, arr, i, env);
	}
	free(buf);
	return (retval);
}
