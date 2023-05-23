#include "shell.h"

/**
 * prompt - Function that prompts the user for input
 * @argv: Pointer to array of arguments
 * @envp: Pointer to the environment
 * Return: Integer
 */
int prompt(char **argv, char **envp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **tokens;
	int status = 1;
	int execute_status;

	while (status)
	{
		_puts("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1 || feof(stdin))
		{
			if (line != NULL)
				free(line);
			break;
		}
		if (line[0] == '\n')
			continue;

		tokens = split(line);
		if (tokens == NULL)
		{
			free(line);
			continue;
		}
		if (_strcmp(tokens[0], "exit") == 0)
		{
			status = 0;
			free(tokens);
			break;
		}
		execute_status = execute(tokens[0], tokens, argv, envp);
		if (execute_status == -1)
		{
			free(tokens);
			break;
		}
		free(tokens);
	}
	exit_shell(status);
	free(line);
	return (0);
}
