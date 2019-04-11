#include "holberton.h"
/**
 * add_node - a function adds a node to linked list from head node
 * @head: a double pointer to head node
 * @str: a pointer to string
 *
 * Return: return the pointer to the node
 */
list_t *add_node(list_t **head, char *str)
{
	list_t *newnode;
	char *s;

	if (str == NULL || head == NULL)
		return (NULL);
	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);
	s = _strdup(str);
	printf("s = %s\n", s);
	if (s == NULL)
	{
		free(newnode);
		return (NULL);
	}
	newnode->str = s;
	printf("newnode -> str = %s\n", newnode->str);
	free(s);
	newnode->next = (*head);
	(*head) = newnode;
	return ((*head));
}
