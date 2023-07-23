#include "shell.h"

void cd(char **env, char *new_dir)
{
	/*size_t size, size_2;
	char *buf = NULL;
	char *buf_2 = NULL;
	char *cwd = getcwd(buf, size);
	char *home = _getenv("HOME");
	char *old_dir = _getenv("OLDPWD");
	char *current_dir = NULL;

	if (new_dir != NULL)
	{
		if (_strcmp(new_dir, "-") != 0)
			if (chdir(new_dir) == -1)
				perror("Chdir");

		if (_strcmp(new_dir, "-") == 0)
			if (chdir(old_dir) == -1)
				perror("Chdir");
	}
	else
		if (chdir(home) == -1)
			perror("Chdir");
	current_dir = getcwd(buf_2, size_2);
	_setenv(env, "PWD", current_dir, 1);
	_setenv(env, "OLDPWD", cwd, 1);
	free(buf);
	free(buf_2);*/
	_setenv(env, "PWD", "NEW", 1);
	_setenv(env, "OLDPWD", "OLD", 1);
}
