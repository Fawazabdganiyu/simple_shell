#include "shell.h"

/**
 * comment_handler - handles comment gracefully
 * @buf1: pointer to string containing comments
 * @buf2: pointer to string to store filtered commands
 */
void comment_handler(char **buf1, char **buf2)
{
	int i, is_q1 = 0, is_q2 = 0, j;
	char *b1 = *buf1, *b2 = *buf2;

	for (i = 0, j = 0; b1[i] && b1[i] != '\n'; i++)
	{
		if (!is_q1 && (b1[i] == '"' || b1[i] == '\''))
			is_q1 = 1;
		else if (!is_q1 && (b1[i] == '"' || b1[i] == '\''))
		{
			is_q2 = 1;
		}
		/*test = echo "#main"*/
		if (b1[i] == '#')
		{
			if (i != 0)
			{
				if (b1[i - 1] != ' ')
					b2[j++] = '#';
			}
			else if ((!is_q1 && !is_q2) || i == 0)
				break;
			else if ((is_q1 && !is_q2))
				b2[j++] = '#';
		}
		else
			b2[j++] = b1[i];
	}
	b2[j] = '\0';
}
