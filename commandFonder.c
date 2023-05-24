#include "main.h"
/**
 * commandFonder - handling the arguments
 * @command: command
 * @path: linked list of system paths
 *
 * Return: the full command or null
 */
char *commandFonder(char *command, list_path *path)
{
	char *full_command, *token;
	list_path *h = path;
	struct stat st;

	if (stat(command, &st) == 0 || command == NULL)
	{
		return (command);
	}
	if (_strcmp(command, "exit") == 0)
		return ("exit");
	while (h != NULL)
	{
		token = h->dir;
		full_command = malloc((lenstr(token) + lenstr(command) + 2) * sizeof(char));

		if (full_command == NULL)
		{
			return (NULL);
		}
		_strcpy(full_command, token);
		_strcat(full_command, "/");
		_strcat(full_command, command);
		_strcat(full_command, "\0");

		if (stat(full_command, &st) == 0)
		{
			return (full_command);
		}
		free(full_command);
		h = h->next;
	}
	return (NULL);
}
