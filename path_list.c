#include "holberton.h"
/**
 * path_list - creates a linked list of the path
 * @head: linked list head
 *
 * Return: returns the linked list head.
 */
list_t *path_list(list_t **head)
{
	char *value, *token;

	value = _getenv();
	if (value == NULL)
		return (NULL);
	token = strtok(value, ":");
	while (token != NULL)
	{
		add_node(head, token);
		token = strtok(NULL, ":");
	}
	return ((*head));
}
