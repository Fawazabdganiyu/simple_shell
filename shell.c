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
	unsigned int t = 0, *m = &t;

	(void)ac;
	program = av[0];
	while (1)
	{
		/* Check if the input stream is from terminal */
		_isatty();

		/* Read input command */
		if (_getline(&buf, &n, STDIN_FILENO) == -1)
			break;

		/* parse the command and handle it properly */
		arr = split_string(buf, delim);

		/* Process the command */
		search_path(arr, program, buf, m);

		/* Execute the input command*/
		_fork(arr, env);
	}

	free(buf);
	_exit(EXIT_SUCCESS);
}
