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

	pid = fork();
	if (pid == -1)
	{
		_free(arr);
		perror("Fork");
		return (1);
	}

	if (pid == 0)
	{
		execve(arr[0], arr, env);
		perror(program);
		_free(arr);
		return (1);
	}

	wait(NULL);
	_free(arr);

	return (0);

}
