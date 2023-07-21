#include "shell.h"

#define LINE_SIZE 1024

/**
 * _getline - reads an entire line from a stream
 * @lineptr: A pointer to the malloc'ed buffer
 * @n: The number of bytes read input the buffer
 * @stream: The standard input stream
 *
 * Return: The number of characters read to the buffer
 *	-1 on failure to read a line
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static size_t index = 0;
	static size_t nread = 0;
	char current_char;

	*lineptr = malloc(sizeof(char) * LINE_SIZE);
	if (!*lineptr)
		return (-1);

	while ((index < nread) || (nread = read(fd, *lineptr, LINE_SIZE) > 0))
	{
		while (index < nread)
		{
			current_char = (*lineptr)[index++];
			if (current_char == '\n')
			{
				(*lineptr)[index - 1] = '\0';
				*n = index;

				return (0);
			}
		}
		/* Make index 0 when the buffer is full and read again */
		index = 0;
	}

	return (-1);
}

