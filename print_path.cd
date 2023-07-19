#include "shell.h"

void print_path()
{
	extern char **environ;

	while (environ)
	{
		printf("%s/\n", *environ);
		environ++;
	}
}

int main()
{
	print_path();
	return (EXIT_SUCCESS);
}
