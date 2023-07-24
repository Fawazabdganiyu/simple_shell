#include "shell.h"

/**
 * handle_command - handles command appropraitely
 * either by calling builtin in or exec
 * @arr: arr of commands
 * @env: environment variables to update when needed
 * @buf: unparsed command <not an array of command yet>
 * string passed in by user
 * @program: name of program being run
 * usually first word in buf and arr
 * @m: (i literally don't know it use :)
 */
void handle_command(char **arr, char **env, char *buf, char *program, u_int *m, char **sep_arr)
{
	if (check_builtin(arr) == 0)
	{
		handle_builtin(arr, buf, env, sep_arr);
		_free(arr);
	}
	/* Process the command */
	else
	{
		search_path(arr, program, buf, m);

		/* Execute the input command*/
		_fork(arr, env);
	}
}
