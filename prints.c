#include "shell.h"

/**
 * _puterr - print a character to stderr
 * @c: The character to print
 *
 * Return:
 * - 1 Success
 * - 1 Error and errno is set appropriately.
 */

int _puterr(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * prmpt - print prompt "$ " to stderr
 *
 * Return:
 *	- 0 Success
 */

int prmpt(void)
{
	write(STDERR_FILENO, "$ ", 2);
	return (0);
}

/**
 * newline - print newline to stderr
 *
 * Return:
 *	- 0 Success
 */

int newline(void)
{
	write(STDERR_FILENO, "\n", 1);
	return (0);
}

/**
 * handle_ctrl_c - handle when user press Ctrl+c
 * it print new line to stderr and call prmpt
 *
 * @sig: signal to send to program
 */

void handle_ctrl_c(int sig __attribute__((unused)))
{
	write(STDERR_FILENO, "\n", 1);
	prmpt();
}

/**
 * _putserr - print a string to stderr
 *
 * @str: string to print
 */

void _putserr(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_puterr(str[i]);
	}
}
