#include "shell.h"

/**
 * get__env - gets the environment variable
 * @key: key to get the value of
 * Return: value of the environment variable
 */

char *get__env(char *key)
{
	char *value = NULL;
	int i = 0, j = 0, len_key = 0;

	if (key == NULL)
		return (NULL);
	len_key = _strlen(key);
	while (environ[i])
	{
		while (environ[i][j] == key[j])
		{
			if (j == len_key - 1)
			{
				value = environ[i] + len_key + 1;
				return (value);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}

/**
 * handle_echo_args - handles the $ builtin
 * @tokens: array of strings
 * @status: exit status
 */

void handle_echo_args(char *tokens, int *status)
{
	char *value = NULL;
	(void)status;

	if (tokens == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return;
	}
	if (_strncmp(tokens, "$", 1) == 0)
	{
		value = get__env(tokens + 1);
		if (value != NULL)
		{
			write(STDOUT_FILENO, value, _strlen(value));
			write(STDOUT_FILENO, "\n", 1);
			return;
		}
	}
	if (_strncmp(tokens, "$$", 2) == 0)
	{
		value = _itoa(getpid());
		write(STDOUT_FILENO, value, _strlen(value));
		write(STDOUT_FILENO, "\n", 1);
		free(value);
		return;
	}
	if (_strncmp(tokens, "$?", 2) == 0)
	{
		write(STDOUT_FILENO, get__env("?"), _strlen(get__env("?")));
		write(STDOUT_FILENO, "\n", 1);
		free(value);
		return;
	}
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * handle_echo - handles the echo builtin with '"'
 * @tokens: array of strings
 * @status: exit status
 * Return: 1 if the command is a builtin, 0 if not
 */

int handle_echo(char **tokens, int *status)
{
	int i = 1, flag = 0, j = 0;

	if (tokens == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	if (_strncmp(tokens[0], "echo", 4) != 0)
		return (0);
	if (tokens[1] == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	if (_strncmp(tokens[1], "$", 1) == 0 || _strncmp(tokens[1], "$$", 2) == 0 ||
	    _strncmp(tokens[1], "$?", 2) == 0)
	{
		handle_echo_args(tokens[1], status);
		return (1);
	}
	for (i = 1; tokens[i] != NULL; i++)
	{
		for (j = 0; tokens[i][j] != '\0'; j++)
		{
			if (tokens[i][j] == '$')
			{
				flag = 1;
				handle_echo_args(tokens[i] + j, status);
				break;
			}
			if (tokens[i][j] != '"')
				write(STDOUT_FILENO, &tokens[i][j], 1);
		}
		if (tokens[i + 1] != NULL)
			write(STDOUT_FILENO, " ", 1);
	}
	if (flag == 0)
		write(STDOUT_FILENO, "\n", 1);
	return (1);
}
