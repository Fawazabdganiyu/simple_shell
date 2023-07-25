#include "shell.h"

/**
 * _fork - creates a child process
 * @arr: A pointer to an argument vector
 * @env: A pointer to environment variables
 *
 * Return: 0 on sucess, 1 otherwise
 */
int _fork(char **arr, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		_free(arr);
		perror("Fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		execve(arr[0], arr, env);
		_free(arr);
		return (-1);
	}

	wait(NULL);
	_free(arr);
	return (-1);
}
