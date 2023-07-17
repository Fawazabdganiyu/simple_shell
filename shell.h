#ifndef _SHELL_H_
#define _SHELL_H_

extern char **environ;

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Processes */
char **split_string(char *str, const char *delim);
unsigned int get_words(char *s);
void _free(char **arr, unsigned int i);
void _isatty();

/* Actions */
size_t _fork(char **arr, size_t i, char **env);
size_t _execve(char **arr, size_t i, char **env);

#endif /* _SHELL_H_ */
