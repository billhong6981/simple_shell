#include "holberton.h"

list_t *path_list(list_t **head)
{
	char *name = "PATH";
	char *value, *token;

	value = getenv(name);
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
