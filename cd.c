#include "shell.h"

void _cd(char *new_dir)
{
	if (_strcmp(new_dir, "-") == 0)
	{
		if (chdir(_getenv("OLDPWD")) == -1)
			perror("Chdir");
		setenv("PWD", _getenv("OLDPWD"), 1);
	}
	
	if (new_dir)
	{
		if (chdir(new_dir) == -1)
			perror("Chdir");
		setenv("PWD", new_dir, 1);
	}

	else
	{
		if (chdir(_getenv("HOME")) == -1)
			perror("Chdir");
		setenv("PWD", _getenv("HOME"), 1);
	}

}
