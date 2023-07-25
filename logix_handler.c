#include "shell.h"

int logix_handler(char *command)
{
	int log_op_no = log_op_in("&&", command), i;
	char **log_sep_arr;

	/*Exit if no logical operator is found*/
	if (log_op_no == 0)
		return (-1);
	
	/*cd && ls && pwd*/
	log_sep_arr = split_string(str, "&&");

	for (i = 0; log_sep_arr[i]; i++)
	{
		/*To be cont'd*/
		if (handle_command(arr, env, buf, program, m, sep_arr))
	}

}
