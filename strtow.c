#include "shell.h"

/**
 * in - checks if a check is in a string
 * @elem: char to check
 * @str: string to check through
 * Return: 1 if elem is present | 0 otherwise
 */
int in(char elem, char *str)
{
	int i;
	for (i = 0; str[i]; i++)
		if (str[i] == elem)
			return (1);
	return (0);
}

int count_word(char *str, char *del)
{
	int i, count = 0, delim = 0;
	int size = strlen(str);

	for (i = 0; str[i]; i++)
	{
		if (!(in(str[i], del)))
		{
			count++;
			delim = 1;
		}
		else
		{
			if (delim == 1)
			{
				count++;
				delim = 0;
			}
		}
	}
	return (count);
}

char *get_str(char *str, char *del)
{
	int i, delim = 0, count = 0;
	char *word = malloc(sizeof(char) * count_word(str, del));

        for (i = 0; str[i]; i++)
        {
                if (!(in(str[i], del)))
                {
                       	word[count] = str[i];
                        delim = 1;
			count++;
                }
                else
                {
                        if (delim == 1 && str[i + 1])
                        {
                                word[count] = str[i];
                                delim = 0;
				count++;
                        }
                }
        }
	if (word[count - 1] == ' ')
		word[count - 1] = '\0';
	else
		word[count] = '\0';
	return (word);
}

char **_strtok(char *str, char *delim)
{
	int size = 0, i, j;
	char **arr, *dup = str, *temp;

	/*this is a boy*/
	temp = str;
	str = get_str(str, delim);
	free(temp);
	temp = NULL;
	for (i = 0; str[i]; i++)
		if (in(str[i], delim))
			size++;
	size++;

	arr = malloc(sizeof(char *) * (size + 1));
	if (arr == NULL)
		return (NULL);
	arr[0] = str;
	/*the kd dj dk jcb*/
	for (i = 1; i < size && *str; str++)
	{
		if (in(*str, delim))
		{
			arr[i++] = str + 1;
			temp = str;
			*temp = '\0';
		}
	}
	arr[i] = temp;
	arr[size] = NULL;
	return (arr);
}


void print_arr(char **arr)
{
	for (; *arr; arr++)
	{
		printf("str-> %s\n", *arr);
	}
}
