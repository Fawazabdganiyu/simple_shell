#ifndef _SHELL_H_
#define _SHELL_H_

extern char **environ;

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/* Processes */
char **split_string(char *str, const char *delim);
unsigned int get_words(char *s);
void _free(char **arr);
void _isatty();
void search_path(char **);
char *make_full_path(char *, char*);
char *_getenv(const char *name);
void free_list(list_t *head);

/* Actions */
void _fork(char *program, char **arr, char **env);
void _exit_(char **command, char *buf);

#endif /* _SHELL_H_ */
