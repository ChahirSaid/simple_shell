#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success, the number of characters written is returned.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _puts - Prints a string
 * @str: Pointer to the string
 * Return: void
 */
void _puts(char *str)
{
	if (str == NULL)
		return;

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
