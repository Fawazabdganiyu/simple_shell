#ifndef _SHELL_H_
#define _SHELL_H_

extern char **environ;

#define INT_BUFFER_SIZE 4
#define BUFFER 1024

typedef unsigned int u_int;

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Processes */
char **split_string(char *str, const char *delim);
void _free(char **arr);
void _isatty(void);
void search_path(char **, char *program, char *buf, unsigned int *n);
char *make_full_path(char *, char*);
char *_getenv(const char *name);
int check_builtin(char **command);
ssize_t _getline(char **lineptr, size_t *n, int fd);
void handle_command(char **arr, char **env, char *buf, char *program, u_int *m, char **sep_arr);
char *break_string(char *str, const char *delim);

/* Actions */
void _fork(char **arr, char **env);
void _error(char *program, char **command, char *buf, unsigned int *n);

/*Built-in handler*/
void handle_builtin(char **command, char *buf, char **env, char **set_arr);

/* Built-in functions */
void _exit_cp(char **command, char *buf, char **set_arr);
void _printenv(char **env);
void cd(char **env, char *new_dir);
int _setenv(char **env, const char *name, const char *value, int overwrite);
int _unsetenv(char **env, const char *name);

/* Helper functions */
int _atoi(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
unsigned int get_words(char *s);
char *uint_to_str(unsigned int num);
int _strncmp(char *s1, const char *s2, size_t n);
size_t count_env(char **env);
char *_strcpy(char *dest, char *src);

#endif /* _SHELL_H_ */
