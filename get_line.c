#include "shell.h"

/**
 * _getline - gets a line from a file descriptor
 * @buffer: buffer to store the line
 * @bufsize: size of the buffer
 * @fd: file descriptor
 * Return: number of characters read
 */

ssize_t _getline(char **buffer, size_t *bufsize, int fd)
{
	ssize_t n_characters = 0;

	if (buffer == NULL || bufsize == NULL)
		return (-1);
	if (*buffer == NULL)
	{
		*buffer = malloc(sizeof(char) * READ_SIZE);
		if (*buffer == NULL)
			return (-1);
		*bufsize = READ_SIZE;
	}
	n_characters = read(fd, *buffer, *bufsize);
	if (n_characters == -1)
	{
		free(*buffer);
		return (-1);
	}
	return (n_characters);
}
