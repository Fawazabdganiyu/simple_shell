#include "shell.h"

/**
 * main - Entry point
 *
 * Description: Simple Shell (CLI)
 *
 * Return: 0 on sucsess
 */
int main(void)
{
	char *buf = NULL, **arr, *delim = " \n", **env = environ;
	size_t n = 0, i, retval;

	while (1)
	{
		_isatty();

		/* Parse the commands */
		if (getline(&buf, &n, stdin) == -1)
			break;

		arr = split_string(buf, delim);
		for (i = 0; arr[i]; i++)
			;

		retval = _fork(arr, i, env);
	}
	free(buf);
	return (retval);
}
