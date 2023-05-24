#include "main.h"
/**
 * arguments - handling the arguments
 * @buffer: the full command
 *
 * Return: 2D array
 */
char **arguments(char *buffer)
{
	char **arg;
	char *token;
	int i;

	arg = malloc(sizeof(char *) * 200);

	if (arg == NULL)
	{
		return (NULL);
	}
	token = strtok(buffer, " \n\t\r\a\v");
	if (token == NULL)
	{
		free(arg);
		return (NULL);
	}
	for (i = 0; token; i++)
	{
		arg[i] = malloc(sizeof(char) * lenstr(token) + 1);
		_strcpy(arg[i], token);
		_strcat(arg[i], "\0");
		token = strtok(NULL, " \n\t\r\a\v");
	}
	arg[i] = NULL;
	return (arg);
}
