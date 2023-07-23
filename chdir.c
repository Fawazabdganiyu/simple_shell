#include "shell.h"

/**
 * cd - changes directory
 * @env: environ to edit
 * @new_dir: new directory to switch to
 */
void cd(char **env, char *new_dir)
{
	size_t size = 0;
	char *buf = NULL;
	char *cwd = getcwd(buf, size);
	char *home = _getenv("HOME");
	char *old_dir = _getenv("OLDPWD");
	char *current_dir = NULL;

	if (new_dir != NULL)
	{
		if ((_strcmp(new_dir, "-") == 0))
			if (chdir(old_dir) == -1)
				perror("Chdir");

		if ((_strcmp(new_dir, "-") != 0))
			if (chdir(new_dir) == -1)
				perror("Chdir");
	}
	else
		if ((chdir(home) == -1))
			perror("Chdir");

	current_dir = getcwd(buf, size);
	_setenv(env, "PWD", current_dir, 1);
	_setenv(env, "OLDPWD", cwd, 1);
	free(buf);
}
