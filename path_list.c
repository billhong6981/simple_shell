#include "holberton.h"
/**
 * path_list - creates a linked list of the path
 * @head: linked list head
 *
 * Return: returns the linked list head.
 */
list_t *path_list(list_t **head)
{
	char *name = "PATH";
	char *value, *value1, *token;

	value = _getenv(name);
	value1 = value;
	if (value == NULL)
		return (NULL);
	if (value[0] == ':')
		add_node(head, ":");
	token = strtok(value, ":");
	while (token != NULL)
	{
		add_node_end(head, token);
		token = strtok(NULL, ":");
	}
	free(value1);
	return ((*head));
}
