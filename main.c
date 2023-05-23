#include "shell.h"

/**
 * main - Main function of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * @envp: Array of environment variables
 * Return: Integer
 */
int main(int argc, char **argv, char **envp)
{
	(void)argc;
	signal(SIGINT, handle_signal);

	prompt(argv, envp);

	return 0;
}
