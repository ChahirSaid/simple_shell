#include "sshell.h"

/**
 * free_grid - free 2D array
 *
 * @grid: 2D array
 */

void free_grid(char **grid)
{
	size_t i;

	if (grid)
	{
		for (i = 0; grid[i]; i++)
		{
			free(grid[i]);
		}
		free(grid);
	}
}

/**
 * free_all - free all
 * @buff: string to be freed
 * @grid: 2D array to be freed
 */
void free_all(char *buff, char **grid)
{
	free(buff);
	free_grid(grid);
}
