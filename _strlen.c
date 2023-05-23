#include "shell.h"
/**
 * _strlen - Returns the length of a string
 * @s: Pointer to the string
 * Return: Length of the string
 */
int _strlen(char *s)
{
int len = 0;
if (s == NULL)
	return 0;
while (s[len] != '\0')
	len++;
return (len);
}
