#include "main.h"
/**
 * sh - shell
 * @list_head: linked list of system paths
 * @a: file name
 */
void sh(list_path *list_head, char *a)
{
	pid_t pid = 0;
	size_t n = 0;
	char *buffer;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print("$ ");
		pid = getline(&buffer, &n, stdin);
		if (pid == -1)
		{
			if (isatty(STDIN_FILENO))
				print("\n");
			exit(EXIT_SUCCESS);
		}
		execute(buffer, list_head, a);
	}
}
