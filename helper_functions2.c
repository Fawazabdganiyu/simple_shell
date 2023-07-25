#include "shell.h"

int _strncmp(char *s1, const char *s2, size_t n);
int xs_space(char *str);

/**
 * _strncmp - compare first n bytes of s1 & s2
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: number of bytes to compare
 * Return: 0 when equal | -1 other wise
 */
int _strncmp(char *s1, const char *s2, size_t n)
{
	int count = 0;

	for (count = 0; n && s2[count]; count++, n--)
	{
		if (s1[count] != s2[count])
			return (-1);
	}
	return (0);
}

/**
 * xs_space - checks if a string is made of only spaces
 * @str: str to check through
 * Return: 0 if str contains other characters
 * -1 otherwise
 */
int xs_space(char *str)
{
	int i;

	for (i = 0; str[i] && str[i] != '\n'; i++)
	{
		if (str[i] != ' ')
			return (0);
	}
	return (-1);
}
