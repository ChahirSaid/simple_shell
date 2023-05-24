#ifndef SSHELL_H
#define SSHELL_H

/* Declare the global variable environ */
extern char **environ;

/* LIBS */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>


/* helpers */

void handle_ctrl_c(int sig __attribute__((unused)));
int prmpt(void);
int newline(void);
char **split_args_by_delim(char *str, char *delim, int *n);
int _atoi(char *s);
int is_number(char *n);
int _isdigit(int c);

/* string lib */

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/* print to stderr*/
void _putserr(char *str);
int _puterr(char c);


/* print to stdout*/
void _puts(char *str);
int _putc(char c);

/* free */
void free_grid(char **grid);
void free_all(char *buff, char **grid);


/* handle path */

char *get_environment_variable_value(char *variable, int index);
char *get_environment_variable(char *variableName);
char **get_directories(char *path);
char *search_command_in_path(char *command, char *search_path);
int is_valid_command(char *command);
char *locate_command(char *command_name);

/* handle built-ins */

void builtin_exit(char *status, char **av, char *sh);
int builtin_env(void);
#endif /* end define sshell.h header*/
