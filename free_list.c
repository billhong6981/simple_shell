#include "holberton.h"
/**
 * free_list - a function free the heap memory allocate by linked list
 * @head: a pointer to head node
 *
 * Return: void
 */
void free_list(list_t *head)
{
/**	if (head == NULL)
		return;
	free_list(head->next);
	free(head->str);
	free(head);
*/
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
