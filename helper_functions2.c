#include "shell.h"

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
