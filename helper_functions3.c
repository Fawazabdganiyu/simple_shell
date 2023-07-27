#include "shell.h"

/**
 * _putchar - prints a char
 * @c: char to print
 * Return: char length = 1;
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @s: str to print
 * Return: str length
 */
int _puts(char *s)
{
	char *str = (s == NULL) ? "(null)" : s;
	int i = 0, retval = 0;

	while (str[i])
	{
		retval += _putchar(str[i++]);
	}

	return (retval);
}

/*
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
