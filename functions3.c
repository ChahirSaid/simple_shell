#include "shell.h"

/**
 * _strtok - tokenizes a string
 * @str: string to tokenize
 * @delim: delimiter
 * Return: pointer to the first token found
 */

char *_strtok(char *str, char *delim)
{
	static char *token;
	static char *next;
	char *delim_ptr;

	if (str != NULL)
		next = str;
	if (next == NULL)
		return (NULL);
	token = next;
	delim_ptr = _strchr(token, *delim);

	if (delim_ptr != NULL)
	{
		*delim_ptr = '\0';
		next = delim_ptr + 1;
	}
	else
		next = NULL;
	return (token);
}

/**
 * _strchr - locates a character in a string
 * @s: string to search
 * @c: character to find
 * Return: pointer to the first occurrence of the character c
 * in the string s, or NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			break;
		i++;
	}

	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: size of the allocated space for ptr
 * @new_size: new size of the new memory block
 * Return: pointer to the new memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0 && ptr != NULL)
		return (NULL);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		new_ptr[i] = ((char *)ptr)[i];

	return (new_ptr);
}
