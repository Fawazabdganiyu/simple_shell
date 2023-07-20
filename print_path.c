#include "shell.h"

/**
 * _printenv - prints the local processes environment
 * variable
 *
 * @env: environment variable
 */
void _printenv(char **env)
{

	int i;

	for (i = 0; env[i + 1] != NULL; i++)
	{
		printf("%s/\n", env[i]);
	}
}
