#include "shell.h"

/**
 * _free - frees a 2D array
 * @arr: A pointer to the array
 */
void _free(char **arr)
{
	free(arr[0]);
	free(arr);
}
