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
	char **sep_arr;
	size_t n = 0;
	char *program;
	unsigned int t = 0, *m = &t, i;
	int status = 0;

	(void)ac;
	program = av[0];
	while (1)
	{
		/* Check if the input stream is from terminal */
		_isatty();

		/* Read input command */
		if (_getline(&buf, &n, STDIN_FILENO) == -1)
			break;
		if (buf[0] == ' ')
			continue;

		/* parse the command and handle it properly */
		sep_arr = split_string(buf, ";\n");

		for (i = 0; sep_arr[i]; i++)
		{
			arr = split_string(sep_arr[i], delim);

		/* Handle the comands <see handle_command.c for description>*/
			handle_command(arr, env, buf, program, m, sep_arr, &status);
		}
		_free(sep_arr);


	}

	free(buf);
	_exit(EXIT_SUCCESS);
}
