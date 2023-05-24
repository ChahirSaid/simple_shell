#include "sshell.h"

/**
 * _strlen - gets length of a string
 * @s: string to check
 * Return: the length of the string s
 */
int _strlen(char *s)
{
	int count = 0;

	if (!s)
		return (count);
	while (*(s + count) > 0)
		count++;
	return (count);
}

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @src: string pointed
 * @dest: buffer pointed
 * Return: the pointer dest
 */
char *_strcpy(char *dest, char *src)
{
	int len = _strlen(src) + 1, i;

	for (i = 0; i < len; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}

/**
 * _strcat - concatenates two strings.
 * append the
 * @src: source string
 * to the
 * @dest: destination string,
 * overwriting the terminating null byte at the end of dest,
 * and the adds a terminating null byte.
 * Return: pointer to the resulting string dest.
 */

char *_strcat(char *dest, const char *src)
{
	int len_dest, len_src, i;

	for (len_dest = 0; *(dest + len_dest) != '\0'; len_dest++)
		;
	for (len_src = 0; *(src + len_src) != '\0'; len_src++)
		;
	for (i = 0; i < len_src && *(src + i) != '\0'; i++)
	{
		*(dest + len_dest + i) = *(src + i);
		*(dest + len_dest + i + 1) = '\0';
	}
	return (dest);
}


/**
 * _strdup - returns a pointer to a new string
 * which is a duplicate of the string str.
 * @str: string.
 * Return:
 * - NULL: if str = NULL or if insufficient memory was available.
 * pointer to the duplicated string.
 */

char *_strdup(char *str)
{
	char *s;
	int i = 0, len = 0;

	if (str == NULL)
		return (NULL);
	/* get str length */
	while (*(str + i) != '\0')
	{
		len++;
		i++;
	}
	s = malloc(sizeof(*str) * (len + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		s[i] = *str;
		str++;
		i++;
	}
	return (s);
}

/**
 * _strcmp - compares two strings
 * @s1: to compare
 * @s2: string to compare to
 * Return: integer indicating the result of the comparison:
 *        0: equal
 *        negative: s1 is less than s2
 *        positive s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	int diff, i;

	i = 0;
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0')
	{
		if (*(s1 + i) != *(s2 + i))
		{
			diff = *(s1 + i) - *(s2 + i);
			break;
		}
		else
		{
			diff = *(s1 + i) - *(s2 + i);
		}
		i++;
	}
	return (diff);
}
