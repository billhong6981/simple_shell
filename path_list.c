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

	value = _getenv("PATH");
	if (value == NULL)
		return (NULL);
	token = strtok(value, ":");
	while (token != NULL)
	{
		printf("%s\n", token);
		add_node(head, token);
		token = strtok(NULL, ":");
	}
	print_list(*head);
	return ((*head));
}
