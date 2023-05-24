#include "shell.h"

/**
 * tokenizez - tokenizes a string using a delimiter
 * @str: string to tokenize
 * @delim: delimiter
 * Return: array of tokens
 */

char **tokenizez(char *str, char *delim)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0, bufsize = 0;

	if (str == NULL)
		return (NULL);
	bufsize = _strlen(str);
	tokens = malloc(sizeof(char *) * bufsize);
	if (tokens == NULL)
		return (NULL);
	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * handle_input - handles the input from the user and executes it
 * handling ; and run multiple commands
 * @buf: buffer to store the input
 * @env: environment variables
 * @av: arguments vector
 * Return: 0 on success
 */

int handle_input(char *buf, char **env, char **av)
{
	char **tokens = NULL, **cmd = NULL;
	int i = 0, bufsize = 0;

	bufsize = _strlen(buf);
	cmd = malloc(sizeof(char *) * bufsize);
	if (cmd == NULL)
		return (-1);
	tokens = tokenizez(buf, ";\n");
	while (tokens[i] != NULL)
	{
		cmd = tokenizez(tokens[i], " \t\r\n\a");
		if (cmd[0] != NULL)
			run_cmd(cmd, env, av);
		free(cmd);
		i++;
	}
	free(tokens);
	return (0);
}

/**
 * sigint_handler - handles the signal SIGINT
 * @signal: signal to handle
 */

void sigint_handler(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 3);
}
