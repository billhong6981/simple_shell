#include "holberton.h"
/**
 * search_file - a function that search filename from PATH directories
 * @head: a head pointer to PATH linked list
 * @str: a string
 * Return: return found string
 */
char *search_file(list_t *head, char *str)
{
	list_t *h = head;
	int len = 0;
	char *s, *s1, *line1, *token1;
	static char array[500];
	struct stat st;

	line1 = _strdup(str);
	token1 = strtok(line1, " ");
	s = &array[499];
	*s = '\0';
	len = _strlen(token1);
	while (len)
		*(--s) = token1[--len];
	if ((*s == '.' && *(s + 1) == '/') || (*s == '/'))
	{
		if (stat(s, &st) == 0)
		{
			free(line1);
			return (s);
		}
	}
	*(--s) = '/';
	while (h != NULL)
	{
		s1 = s;
		len = _strlen(h->str);
		while (len)
			*(--s1) = (h->str)[--len];
		if (stat(s1, &st) == 0)
		{
			free(line1);
			return (s1);
		}
		h = h->next;
	}
	free(line1);
	return (NULL);
}
