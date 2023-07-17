#include "shell.h"

/**
 * _free - frees a 2D array
 * @arr: A pointer to the array
 * @i: Number of elements in the array
 */
void _free(char **arr, unsigned int i)
{
	unsigned int j;

	for (j = 0; j < i; j++)
		free(arr[j]);
	free(arr);
}
