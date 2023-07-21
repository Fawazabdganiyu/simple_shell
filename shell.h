#ifndef _SHELL_H_
#define _SHELL_H_

extern char **environ;

#define INT_BUFFER_SIZE 4

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
char **split_string(char *str, const char *delim, char **env);
void _free(char **arr);
void _isatty();
void search_path(char **, char *program, char* buf, unsigned int *n);
char *make_full_path(char *, char*);
char *_getenv(const char *name);
int check_builtin(char **command);

/* Actions */
void _fork(char **arr, char **env);
void _error(char *program, char **command, char *buf, unsigned int *n);

/*Built-in handler*/
void handle_builtin(char **command, char *buf, char **env);

/* Built-in functions */
void _exit_(char **command, char *buf);
void _printenv(char **env);

/* Helper functions */
int _atoi(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
unsigned int get_words(char *s);
char * uint_to_str(unsigned int num);
int _strncmp(char *s1, const char *s2, size_t n);
int row_num(char *str);
void _free_fail(char **arr, int n);
char **strtow(char *str);
char **_strtok(char *str, char *delim);
void print_arr(char **arr);
char *get_str(char *str, char *del);
int count_word(char *str, char *del);
int in(char elem, char *str);

#endif /* _SHELL_H_ */
