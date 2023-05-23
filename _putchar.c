#include "shell.h"
#include <unistd.h>
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
