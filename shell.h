#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024

int execute(char *cmd, char **argv, char **av, char **envp);
void handle_ctrl(int signal);
int prompt(char **argv, char **envp);
char **split(char *line);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
char *path(char *cmd);
void exit_shell(int status);
void print_environment(char **envp);
char *get_environment_variable(const char *name);
int _strcmp(char *s1, char *s2);

#endif
