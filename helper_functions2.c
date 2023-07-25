#include "shell.h"

int _strncmp(char *s1, const char *s2, size_t n);
int log_op_in(char *log_op, char *str);

/**
 * log_op_in - checks if a specific logical operator is in a str
 * @log_op: logical operator to search for
 * @str: string to search through
 * Return: Number of times logical operator appears in string
 */
int log_op_in(char *log_op, char *str)
{
	int log = 0, i, retval = 0;
	for (i = 0; str[i]; i++)
	{
		if (log && str[i] == log_op[0])
			retval++;
		if (!log && str[i] == log_op[0])
			log = 1;
	}
	return (retval);
}

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
