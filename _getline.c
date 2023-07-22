#include "shell.h"

#define INITIAL_SIZE 256
#define ONE_BYTE 1

/**
 * _getline - reads an entire line from a stream
 * @lineptr: A pointer to the malloc'ed buffer
 * @n: The number of bytes read input the buffer
 * @fd: The standard input file descriptor
 *
 * Return: The number of characters read to the buffer
 *	-1 on failure to read a line
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	size_t nread = 0, c;
	size_t buf_size = *n;
	char *new_ptr;

	if (*lineptr == NULL || buf_size == 0)
	{
		*lineptr = malloc(sizeof(char) * INITIAL_SIZE);
		if (*lineptr == NULL)
			return (-1);
		buf_size = INITIAL_SIZE;
	}

	while ((c = read(fd, &(*lineptr)[nread++], ONE_BYTE)) > 0)
	{
		/* Reallocate if the malloc'ed is not sufficient */
		if (nread >= buf_size)
		{
			buf_size *= 2;
			new_ptr = realloc(*lineptr, sizeof(char) * buf_size);
			if (!new_ptr)
				return (-1);
			*lineptr = new_ptr;
		}
		/* Detect if a new line is read and initialise */
		/* the next character '\0' then return */
		if ((*lineptr)[nread - 1] == '\n')
		{
			(*lineptr)[nread] = '\0';
			*n = nread;
			return (nread);
		}
	}
	/* Return what has been read on EOF */
	if (nread > 0)
	{
		(*lineptr)[nread] = '\0';
		*n = nread;
		return (nread);
	}
	return (-1);
}
