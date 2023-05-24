#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

#define READ_SIZE 1024
#define BUFSIZE 1024

extern char **environ;

/* get_line.c */
ssize_t _getline(char **buffer, size_t *bufsize, int fd);

/* input.c */
int handle_input(char *buf, char **env, char **av);
void sigint_handler(int sigint);
char **tokenizez(char *str, char *delim);

/* split_string.c */
char **tokenize(char *buf);

/* builtins.c */
void print_env(char **env);
int builtins(char **tokens, char **env);
int handle_setenv_unsetenv(char **tokens);
int handle_clear_cd(char **tokens);
int handle_exit(char **tokens, char **env);

/* functions1.c */
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *str1, char *str2, int n);
char *_strdup(char *str);
char *_strcatpath(char *dest, char *src);

/* functions2.c */
int _atoi(char *str);
char *_strcpy(char *dest, char *src);
char *_itoa(int num);
int _constcharlen(const char *str);
void print_error(char *av, int count, char *cmd, char *msg);

/* functions3.c */
char *_strchr(char *s, char c);
char *_strtok(char *str, char *delim);
char *_strcat(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* free_array.c */
void free_array(char **array);

/* check_cmd.c */
int check_cmd(char *cmd);

/* get_path.c */
char *get_path(char *cmd);
char *make_path(char *path, char *cmd);

/* run_cmd.c */
int run_cmd(char **tokens, char **env, char **av);
void pr_error(char **tokens, char **av);
int fork_run(char **tokens, char **env);

/* env.c */
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *key);
int len_env(char **env);
char *_getenv(char *key);

/* dir.c */
void directory(char **args);
void change_directory(char **directories, char *command_name);

/* echo.c */
int handle_echo(char **tokens, int *status);
void handle_echo_args(char *tokens, int *status);
char *get__env(char *key);
/* str.c */
int _putchar(char c);
void _puts(char *str);

/* main.c */
char *cut_string(char *str);
#endif /* SHELL_H */

