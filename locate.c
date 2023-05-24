#include "sshell.h"

/**
 * get_directories - split the PATH variable to dirs paths
 *
 * @path: PATH variable value
 *
 * Return: array of paths
 */

char **get_directories(char *path)
{
	int num_directories = 0;
	char **directories;

	directories = split_args_by_delim(path, ":", &num_directories);

	return (directories);
}

/**
 * search_command_in_path - test the command in each path
 *
 * @command: command string value
 * @search_path: PATH variable value
 *
 * Return:
 *	- The path for the entered command
 *	- NULL if not found
 */

char *search_command_in_path(char *command, char *search_path)
{
	unsigned int index;
	struct stat file_stats;
	char **directories;
	char *command_path;

	index = 0;
	directories = get_directories(search_path);
	while (directories[index])
	{
		command_path = malloc((_strlen(directories[index]) +
							   _strlen(command) + 2) * sizeof(char));
		if (!command_path)
			return (command_path);
		_strcpy(command_path, directories[index]);
		_strcat(command_path, "/");
		_strcat(command_path, command);
		_strcat(command_path, "\0");
		if (stat(command_path, &file_stats) == 0)
		{
			return (command_path);
		}
		free(command_path);
		index++;
	}
	return (NULL);
}

/**
 * is_valid_command - check if the command alone is valid
 *
 * @command: command string value
 *
 * Return:
 *	- 1 unvalid command
 *	- 0 command working
 */

int is_valid_command(char *command)
{
	struct stat command_stats;

	if (!*command)
		return (1);
	if (stat(command, &command_stats) == 0)
	{
		return (0);
	}
	return (1);
}


/**
 * locate_command - main function to handle path
 *
 * @command_name: command string value
 *
 * Return:
 *	- The command name
 *	- The command path
 *	- NULL
 */

char *locate_command(char *command_name)
{
	char *path = NULL;
	char *path_found = NULL;

	if (command_name != NULL)
	{
		if (is_valid_command(command_name))
		{
			path = get_environment_variable("PATH");
			if (path != NULL)
				path_found = search_command_in_path(command_name, path);
			if (path_found != NULL)
				return (path_found);
		}
		return (command_name);
	}
	return (NULL);
}
