#include "main.h"

/**
 * add_node_end - adding nodes to the end of linked list
 * @head: the head of the linked list
 * @n: path
 *
 * Return: the NEW Node
 */

list_path *add_node_end(list_path **head, char *n)
{
	list_path *new;
	list_path *old = *head;

	while (old != NULL && old->next != NULL)
		old = old->next;

	new = malloc(sizeof(list_path));
	if (new == NULL)
		return (NULL);

	new->dir = n;
	new->next = NULL;

	if (old == NULL)
	{
		*head = new;
		return (new);
	}
	else
		old->next = new;

	return (new);
}

/**
 * adding_path - adding nodes to the end of linked list
 * @head: the head of the linked list
 *
 * Return: length of linked list
 */

int adding_path(list_path **head)
{
	char *key = NULL, *path = _getpath("PATH");
	int i = 0;

	if (path != NULL)
	{
		key = strtok(path, ":");
	}
	while (key)
	{
		add_node_end(head, key);
		i++;
		key = strtok(NULL, ":");
	}
	return (i);
}
