#include "shell.h"

/**
 * reverse - reverses a string
 * @s: string to reverse*
 */
void reverse(char *s)
{
	int len, i, tmp;

	len = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}

	for (i = len - 1; i >= len / 2 ; i--)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
}

/**
 * uint_to_str - converts  unsigned integer to string
 * @num: The number to be printed
 *
 * Return: The converted unisigned int.
 */
char * uint_to_str(unsigned int num)
{
	int i = 0;
	char *s;

	s = malloc(sizeof(char) * INT_BUFFER_SIZE);
	if (!s)
		return (NULL);

	while (num > 0)
	{
		s[i++] = (num % 10) + '0';
		num /= 10;
	}
	s[i] = '\0';

	reverse(s);

	return (s);
}
