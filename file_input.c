#include "shell.h"

int file_input(char **av, char **env, char *buf, char *program, u_int *m, int *status, char *delim)
{
	char *file = av[1], *buffer = NULL;
	char **arr, **sep_arr;
	size_t size = 0;
	int nread = 0, i;
	FILE *file_holder = NULL;

	if (file == NULL || xs_space(file) == -1)
                        return ('x');

	if (access(file, F_OK) == -1)
	{
		/*Implicit Error Handling*/
		_puts(program);
		_puts(": ");
		put_u_int(*m);
		_puts(": cannot open ");
		_puts(file);
		_puts(": No such file\n");
		return (0);
	}
	file_holder = fopen(file, "r");

	while ((nread = getline(&buffer, &size, file_holder)) > 0)
	{
		if (xs_space(buffer) == -1)
		{
			continue;
		}
		sep_arr = split_string(buffer, ";\n");

		for (i = 0; sep_arr[i]; i++)
		{
			arr = split_string(sep_arr[i], delim);

		/* Handle the comands <see handle_command.c for description>*/
			handle_command(arr, env, buf, program, m, sep_arr, status);
		}
		_free(sep_arr);
	}
	free(buffer);
	fclose(file_holder);
	return (0);
}
