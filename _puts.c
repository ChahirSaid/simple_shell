#include "shell.h"
/**
 * _puts - Prints a string
 * @str: Pointer to the string
 * Return: void
 */
void _puts(char *str)
{
if (str == NULL)
return;
int i = 0;
while (str[i] != '\0')
{
	_putchar(str[i]);
	i++;
}
}
