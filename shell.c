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
	size_t n = 0;
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

		search_path(arr);
		printf("--<%s>---\n", arr[0]);
		_fork(program, arr, env);
	}
	free(buf);
	_exit(EXIT_SUCCESS);
}
