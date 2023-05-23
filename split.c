#include "shell.h"

/**
 * split - Function to split a string into tokens
 * @line: Pointer to the string
 * Return: Array of tokens
 */
char **split(char *line)
{
	char *token;
	char **tokens = malloc(100 * sizeof(char *));
	int i = 0;

	if (!tokens)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");
	while (token != NULL && i < 99)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}
