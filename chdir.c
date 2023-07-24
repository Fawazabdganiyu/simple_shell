#include "shell.h"

/**
 * cd - changes directory
 * @env: environ to edit
 * @new_dir: new directory to switch to
 */
void cd(char **env, char *new_dir)
{
	char buf[1024];
	char buf_2[1024];
	char *cwd = getcwd(buf, BUFFER);
	char *home = _getenv("HOME");
	char *old_dir = _getenv("OLDPWD");
	char *current_dir = NULL;

	if (new_dir != NULL)
	{
		if ((_strcmp(new_dir, "-") == 0))
		{
			if (chdir(old_dir) == -1)
				perror("Chdir");
			printf("%s\n", old_dir);
		}

		if ((_strcmp(new_dir, "-") != 0))
			if (chdir(new_dir) == -1)
				perror("Chdir");
	}
	else
		if (chdir(home) == -1)
			perror("Chdir");
	current_dir = getcwd(buf_2, BUFFER);
	_setenv(env, "PWD", current_dir, 1);
	_setenv(env, "OLDPWD", cwd, 1);
}
