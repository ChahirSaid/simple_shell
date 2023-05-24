#include "main.h"
/**
 * main - simple shell
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char **argv)
{
	list_path *list_head = NULL;

	(void)argc;
	adding_path(&list_head);
	sh(list_head, argv[0]);
	return (EXIT_SUCCESS);
}
