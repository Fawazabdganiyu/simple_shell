#include "shell.h"

int _strcmp(char *s1, char *s2)
{
	int l1 = strlen(s1), l2 = strlen(s2), count = 0;
	if (l1 != l2)
		return (-1);
	for (count = 0; s1[count] && s2[count]; count++)
	{
		if (s1[count] != s2[count])
			return (-1);
	}
	return (0);
}

char *_getenv(char *str)
{
	extern char **environ;
	int i;
	char *key;
	for (i = 0; environ[i] != NULL; i++)
	{
		key = strtok(environ[i], "=\n");
		if ((strcmp(key, str)  == 0))
		{
			key = strtok(NULL, "=\n");
			return (key);
		}
	}
	return (NULL);
}

