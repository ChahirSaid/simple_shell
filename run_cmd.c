#include "shell.h"

/**
 * pr_error - prints an error message
 * @tokens: tokens
 * @av: argv
 * Return: void
 */

void pr_error(char **tokens, char **av)
{
	int ex_status;

	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": line 1: ", 10);
	write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
	write(STDERR_FILENO, ": command not found\n", 20);
	ex_status = 127;
	_setenv("?", _itoa(ex_status), 1);
}

/**
 * fork_run - forks and runs a command
 * @tokens: tokens
 * @env: environment variables
 * Return: 0 on success, 1 on failure.
 */

int fork_run(char **tokens, char **env)
{
	pid_t pid;
	int status;
	char *path;
	struct stat st;

	if (stat(tokens[0], &st) == 0)
		path = _strdup(tokens[0]);
	else
		path = get_path(tokens[0]);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		_setenv("?", "127", 1);
		free(path);
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(path, tokens, env) == -1)
		{
			perror("Error");
			_setenv("?", "127", 1);
			free(path);
			exit(1);
		}
	}
	else
	{
		wait(&status);
		_setenv("?", _itoa(status), 1);
	}
	free(path);
	return (0);
}

/**
 * run_cmd - runs a command
 * @tokens: tokens
 * @env: environment variables
 * @av: argv
 * Return: 0 on success, 1 on failure.
 */

int run_cmd(char **tokens, char **env, char **av)
{
	int is_built_in = 0, cmd_exits = 0;

	is_built_in = builtins(tokens, env);
	cmd_exits = check_cmd(tokens[0]);
	if (is_built_in == 0 && cmd_exits == 1)
	{
		fork_run(tokens, env);
		return (0);
	}
	if (is_built_in == 0 && cmd_exits == 0)
	{
		pr_error(tokens, av);
		return (1);
	}
	return (0);
}
