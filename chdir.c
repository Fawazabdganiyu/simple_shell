#include "shell.h"

void cd(char **env, char *new_dir)
{
	size_t size = 0;
	char *buf = NULL;
	char *cwd = getcwd(buf, size);
	char *home = _getenv("HOME");
	char *old_dir = _getenv("OLDPWD");
	char *current_dir = NULL;

	(void)env;
	if (new_dir != NULL)
	{
		if ((_strcmp(new_dir, "-") == 0))
		{	if (chdir(old_dir) == -1)
				perror("Chdir");
		}
		else
		{
			if (chdir(new_dir) == -1)
				perror("Chdir");
		}
	}
	if (chdir(home) == -1)
		perror("Chdir");

	current_dir = getcwd(buf, size);
	setenv("PWD", current_dir, 1);
	setenv("OLDPWD", cwd, 1);
	free(buf);
}
