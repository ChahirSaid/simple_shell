#include "shell.h"

/**
 * free_array - frees an array of strings
 * @array: array of strings
 * Return: void
 */

void free_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
