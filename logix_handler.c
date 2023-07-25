#include "shell.h"

int logix_handler(char *command char **env, char *buf, char *program, int *m, char *sep_arr)
{
	int log_op_no = log_op_in("&&", command), i;
	int check;
	char **log_sep_arr;

	(void)env;
	(void)buf;
	(void)program;
	(void)m;
	(void)sep_arr;
	/*Exit if no logical operator is found*/
	if (log_op_no == 0)
		return (-1);
	
	/*cd && ls && pwd*/
	log_sep_arr = split_string(command, "&&");

	for (i = 0; log_sep_arr[i]; i++)
	{
		check = handle_command(log_sep_arr + i, env, buf,
				program, m, sep_arr)
			if (check == 1)
				return (-1);
	}

}
