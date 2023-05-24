#include "sshell.h"

/**
 * split_args_by_delim - splits a string according to
 * a specific set of delimetres
 *
 * @str: string to split
 * @delim: string of delims characters
 * @n: number of args returned
 *
 * Return:
 *	- array of string splited to substrings
 *	- NULL
 */

char **split_args_by_delim(char *str, char *delim, int *n)
{
	char **words, *tok;
	int i = 0, j = 0, count = 0;

	if (!str)
		return (NULL);
	/* count limits */
	while (*(str + i) != '\0')
	{
		while (*(delim + j) != '\0')
		{
			if (*(str + i) == *(delim + j))
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	tok = strtok(str, delim);
	words = malloc((count + 2) * sizeof(char *));
	i = 0;
	while (tok)
	{
		words[i] = malloc(_strlen(tok) + 1);
		_strcpy(words[i], tok);
		i++;
		tok = strtok(NULL, delim);
	}
	words[i] = NULL;
	*n = count + 1;
	return (words);
}
