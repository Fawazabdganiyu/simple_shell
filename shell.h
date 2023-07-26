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
#include <limits.h>

/* Processes */
char **split_string(char *str, const char *delim);
void _free(char **arr);
void _isatty(void);
void search_path(char **, char *program, char *buf, unsigned int *n);
char *make_full_path(char *, char*);
char *_getenv(const char *name);
int check_builtin(char **command);
ssize_t _getline(char **lineptr, size_t *n, int fd);
void handle_command(char **arr, char **env, char *buf, char *program,
		u_int *m, char **sep_arr, int *status);
int xs_space(char *str);

/* Actions */
void _fork(char **arr, char **env, int *status);
void _error(char *program, char **command, char *buf, unsigned int *n);
void _error_cd(char *program, char **command, char *buf, unsigned int *n);

/*Built-in handler*/
void handle_builtin(char **command, char *buf, char **env,
		char **set_arr, int *status, char *program, unsigned int *n);

/* Built-in functions */
void _exit_cp(char **command, char *buf, char **set_arr);
void _printenv(char **env);
void cd(char **env, char **command, char *program, char *buf, unsigned int *n);
int _setenv(char **env, const char *name, const char *value, int overwrite);
int _unsetenv(char **env, const char *name);
void _echo_status(int *status);
void _getpid(void);

/* Helper functions */
int _atoi(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
unsigned int get_words(char *s);
int put_u_int(unsigned int num);
int _strncmp(char *s1, const char *s2, size_t n);
size_t count_env(char **env);
char *_strcpy(char *dest, char *src);
int put_int(int num);
void reverse(char *s);
int _puts(char *s);
int _putchar(char c);
void *_realloc(void *ptr, size_t old_size, size_t new_size);

#endif /* _SHELL_H_ */
