#include "shell.h"

/**
 * _fork - creates a child process
 * @arr: A pointer to an argument vector
 * @i: Number of elements in the array
 * @env: A pointer to environment variables
 *
 * Return: 0 on sucess, 1 otherwise
 */
size_t _fork(char **arr, size_t i, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		_free(arr, i);
		perror("Fork");
		return (1);
	}

	if (pid == 0)
	{
		execve(arr[0], arr, env);
		perror(arr[0]);
		_free(arr, i);
		return (1);
	}

	wait(NULL);
	_free(arr, i);

	return (0);

}
