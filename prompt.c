#include "shell.h"

/**
 * get_path - Function to find the full path of a command
 * @cmd: Pointer to the command
 * Return: Pointer to the full path of the command,
		or NULL if not found
 */
char *get_path(char *cmd)
{
	char *path = get_environment_variable("PATH");
	char *token, *path_copy;
	char *full_path = NULL;

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("Failed to allocate memory");
		return (NULL);
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(cmd) + 2);
		if (full_path == NULL)
		{
			perror("Failed to allocate memory");
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", token, cmd);
		if (access(full_path, X_OK) == 0)
			break;
		free(full_path);
		full_path = NULL;
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (full_path);
}
