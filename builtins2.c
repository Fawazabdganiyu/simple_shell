#include "shell.h"

/**
 * _getpid - gets PID
 */
void _getpid(void)
{
	unsigned int  my_pid;

	my_pid = (unsigned int)getpid();

/*	put_u_int(my_pid); */
	printf("%u\n", my_pid);
/*	_putchar('\n'); */
}

/**
 * _echo_status - echos return status
 * @status: status integer value
 */
void _echo_status(int *status)
{
	put_int(*status);
	_putchar('\n');
}
