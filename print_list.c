#include "holberton.h"
/**
 * print_list - a function iterate all the linked list node and print it
 * @h: a pointer to head of first node
 *
 * Return: return numbers of node printed on sucess
 */
size_t print_list(list_t *h)
{
	size_t i;

	for (i = 0; h != NULL; i++)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%lu] %s\n", i, h->str);
		h = h->next;
	}
	return (i);
}
