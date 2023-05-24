#include "shell.h"
/**
 * _putc - print a character to stdout
 * @c: The character to print
 *
 * Return:
 * - 1 Success
 * - 1 Error and errno is set appropriately.
 */

int _putc(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _puts - print a string to stdout
 *
 * @str: string to print
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putc(str[i]);
	}
}
