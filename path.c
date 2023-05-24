#include "shell.h"

/**
 * make_path - makes a path
 * @path: path to make
 * @cmd: command to add to path
 * Return: path
 */

char *make_path(char *path, char *cmd)
{
	char *cmd_path = NULL;

	cmd_path = malloc(sizeof(char) * (_strlen(path) + _strlen(cmd) + 2));
	if (cmd_path == NULL)
		return (NULL);
	_strcpy(cmd_path, path);
	_strcat(cmd_path, "/");
	_strcat(cmd_path, cmd);
	return (cmd_path);
}

/**
 * get_path - gets the path of a command
 * @cmd: command to get the path of
 * Return: path of the command
 */

char *get_path(char *cmd)
{
	char *path = NULL, *path_copy = NULL, *token = NULL, *cmd_path = NULL;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (cmd);
	if (cmd == NULL)
		return (NULL);
	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	path = _getenv("PATH");
	path_copy = _strdup(path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		cmd_path = make_path(token, cmd);
		if (stat(cmd_path, &st) == 0)
		{
			free(path_copy);
			return (cmd_path);
		}
		free(cmd_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
