#include "sshell.h"

/**
 * handle_builtins - handle built-ins functions
 *
 * @command: command entred by user
 * @buff: readed line
 * @args: arrays of args
 * @sh: program name
 */

void handle_builtins(char *command, char *buff, char **args, char *sh)
{
	if (command)
	{
		if (_strcmp(command, "exit") == 0)
		{
			free(buff);
			builtin_exit(args[1], args, sh);
		}
		if (_strcmp(command, "env") == 0)
			builtin_env();
	}
}

/**
 * execute_command - handle command
 * execution for main function
 *
 * @command: command passed to shell
 * @buff: line readed by getline without newline
 * @env: program environment
 * @sh: program name
 */

void execute_command(char *command, char *buff, char **env, char *sh)
{
	char **cmd_args = NULL;
	int argsn = 0;
	pid_t pid;
	int status;

	cmd_args = split_args_by_delim(command, " ", &argsn); /* t2 */
	if (cmd_args)
		handle_builtins(cmd_args[0], buff, cmd_args, sh);
	pid = fork(); /* task 1 */
	if (pid == -1)
	{
		free_all(buff, cmd_args); /* task 2 */
		perror("Error fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (cmd_args && *cmd_args) /* task 3 */
		{
			*cmd_args = locate_command(*cmd_args);/* task 3 */
			if (execve(cmd_args[0], cmd_args, env) == -1) /* task 2 */
			{
				perror(cmd_args[0]); /* task 1 */
				free_all(buff, cmd_args);/* task 2 */
				exit(EXIT_FAILURE);
			}
		}
		free_all(buff, cmd_args); /* task 2 */
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			errno = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			errno = 128 + WTERMSIG(status);
	}
	free_all(buff, cmd_args); /* task 2 */
}

/**
 * main - Entry point to a simple shell program
 *
 * @ac: number of args passed to it
 * @av: array of args passed to it
 * @env: program environment
 *
 * Return:
 *	- 0 Success(Alwayse)
 */

int main(int ac, char *av[], char **env)
{
	char *buff = NULL, *command = NULL, *sh;
	size_t bs = 0;
	ssize_t r = 0;

	(void)ac;
	sh = av[0];
	signal(SIGINT, handle_ctrl_c); /* task 1 */
	while (1) /* task 1 */
	{
		if (isatty(STDIN_FILENO))
			prmpt();/* task 1 */
		r = getline(&buff, &bs, stdin); /* task 1 */
		if (r == -1)
		{
			if (isatty(STDIN_FILENO))
				newline();
			if (buff)
				free(buff);
			exit(EXIT_SUCCESS);
		}
		command = strtok(buff, "\n"); /* task 1 */
		/* Calling execute_command function */
		execute_command(command, buff, env, sh);
		buff = NULL;
	}
	free(buff);
	return (0);
}
