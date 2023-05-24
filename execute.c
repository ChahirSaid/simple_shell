#include "main.h"
/**
 * ffree - freeing the two Dimensional array
 * @pp: the two Dimensional array
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
/**
 * forkk - Executing the command if it's available.
 * @com: the command
 * @arg: arguments
 */

void forkk(char *com, char **arg)
{
	int status;
	pid_t pid;

	if (_strcmp(com, "exit") == 0)
		exit(0);

	pid = fork();
	if (pid == 0)
	{
		if (execve(com, arg, environ) < 0)
		{
			perror(arg[0]);
			return;
		}
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
		if (com != arg[0])
			free(com);
		ffree(arg);
	}
}
/**
 * execute - Executing the command if it's available.
 * @command: the command
 * @list_head: linked list of system paths
 * @ag: file name
 */

void execute(char *command, list_path *list_head, char *ag)
{
	char **arg, *com = NULL;

	if (_strcmp(command, "\n") == 0)
		return;

	arg = arguments(command);
	if (arg != NULL)
	{
		com = commandFonder(arg[0], list_head);
		if (com != NULL)
		{
			forkk(com, arg);
		}
		else
		{
			ffree(arg);
			perror(ag);
		}
	}
}
