#include "shell.h"

/**
 * cd - changes directory
 * @env: environ to edit
 * @new_dir: new directory to switch to
 */
void cd(char **env, char **command, char *program, char *buf, unsigned int *n)
{
	char buff[1024];
	char buf_2[1024];
	char *cwd = getcwd(buff, BUFFER);
	char *home = _getenv("HOME");
	char *old_dir = _getenv("OLDPWD");
	char *current_dir = NULL;

	if (command[1] != NULL)
	{
		if ((_strcmp(command[1], "-") == 0))
		{
			if (chdir(old_dir) == -1)
				_error_cd(program, command, buf, n);
			printf("%s\n", old_dir);
		}

		if ((_strcmp(command[1], "-") != 0))
			if (chdir(command[1]) == -1)
				_error_cd(program, command, buf, n);
	}
	else
		if (chdir(home) == -1)
			_error_cd(program, command, buf, n);
	current_dir = getcwd(buf_2, BUFFER);
	_setenv(env, "PWD", current_dir, 1);
	_setenv(env, "OLDPWD", cwd, 1);
}
