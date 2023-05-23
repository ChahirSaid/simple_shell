#include "shell.h"

/**
 * main - Main function of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * @envp: Array of environment variables
 * Return: Integer
 */
int main(__attribute__((unused)) int argc, char **argv, char **envp)
{

	prompt(argv, envp);

	return (0);
}
