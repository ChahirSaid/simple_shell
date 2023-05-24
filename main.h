#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define GETLINE getline
#define STRTOK strtok

/* Global variable */
extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @next: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *next;
} list_path;

int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void print(char *s);
int lenstr(char *s);
list_path *add_nodeint_end(list_path **head, const char *n);
int adding_path(list_path **head);
size_t print_listint(const list_path *h);
char *_getpath(char *path_name);
char *commandFonder(char *command, list_path *path);
char **arguments(char *buffer);
void execute(char *command, list_path *list_head, char *ag);
void sh(list_path *list_head, char *ag);

#endif
