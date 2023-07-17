#include "shell.h"

/**
 * _fork - creates a child process
 * @program: The name of the shell program
 * @arr: A pointer to an argument vector
 * @i: Number of elements in the array
 * @env: A pointer to environment variables
 *
 * Return: 0 on sucess, 1 otherwise
 */
size_t _fork(char *program, char **arr, char **env)
{
	pid_t pid;
	char *prog = arr[0];

	prog = search_path(prog);
	if (!prog)
	{
		perror(program);
		return (-1);
	}
	arr[0] = prog;
	pid = fork();
	if (pid == -1)
	{
		_free(arr);
		perror("Fork");
		return (1);
	}

	if (pid == 0)
	{
		execve(prog, arr, env);
		perror(program);
		_free(arr);
		return (1);
	}

	wait(NULL);
	_free(arr);

	return (0);

}
