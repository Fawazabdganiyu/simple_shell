#include "shell.h"

/**
 * _isdigit - checks for a digit (0 through 9)
 * @str: character pointer to check
 *
 * Return: 1 if c is a digit, 0 if otherwise
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

