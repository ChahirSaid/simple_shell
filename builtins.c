#include "shell.h"

/**
 * print_env - prints the environment variables
 * @env: environment variables
 */

void print_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * builtins - handles the builtins
 * @tokens: array of strings
 * @env: environment variables
 * Return: 1 if the command is a builtin, 0 if not
 */

int builtins(char **tokens, char **env)
{
	if (handle_exit(tokens, env))
		return (1);
	if (handle_setenv_unsetenv(tokens))
		return (1);
	if (handle_clear_cd(tokens))
		return (1);
	return (0);
}

/**
 * handle_exit - handles the builtins
 * @tokens: array of strings
 * @env: environment variables
 * Return: 1 if the command is a builtin, 0 if not
 */

int handle_exit(char **tokens, char **env)
{
	int i = 0;

	if (_strncmp(tokens[0], "exit", 4) == 0)
		exit(EXIT_SUCCESS);
	if (_strncmp(tokens[0], "env", 3) == 0)
	{
		while (env[i] != NULL)
		{
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		return (1);
	}
	return (0);
}

/**
 * handle_setenv_unsetenv - handles the builtins
 * @tokens: array of strings
 * Return: 1 if the command is a builtin, 0 if not
 */

int handle_setenv_unsetenv(char **tokens)
{
	if (_strncmp(tokens[0], "setenv", 6) == 0)
	{
		if (tokens[1] == NULL)
		{
			write(STDERR_FILENO, "Usage: setenv [VARIABLE] [VALUE]\n", 33);
			return (1);
		}
		if (tokens[2] == NULL)
		{
			_setenv(tokens[1], "", 1);
			return (1);
		}
		_setenv(tokens[1], tokens[2], 1);
		return (1);
	}
	if (_strncmp(tokens[0], "unsetenv", 8) == 0)
	{
		if (tokens[1] == NULL)
		{
			write(STDERR_FILENO, "Usage: unsetenv [VARIABLE]\n", 27);
			return (1);
		}
		_unsetenv(tokens[1]);
		return (1);
	}
	return (0);
}

/**
 * handle_clear_cd - handles the builtins
 * @tokens: array of strings
 * Return: 1 if the command is a builtin, 0 if not
 */

int handle_clear_cd(char **tokens)
{
	if (_strncmp(tokens[0], "clear", 5) == 0)
	{
		write(STDOUT_FILENO, "\033[H\033[J", 6);
		return (1);
	}
	if (_strncmp(tokens[0], "echo", 4) == 0)
	{
		handle_echo(tokens, NULL);
		return (1);
	}
	if (_strncmp(tokens[0], "cd", 2) == 0)
	{
		directory(tokens);
		return (1);
	}
	return (0);
}
