#include "holberton.h"

char *search_file(list_t *head, char *str)
{
	int len = 0;
	char *s, *line, *token1;
	static char array[200];
	struct stat st;

	line = _strdup(str);
	token1 = strtok(line, " ");
	s = &array[199];
	*s = '\0';
	while (head != NULL)
	{
		len = _strlen(token1);
		while (len)
			*(--s) = token1[--len];
		len = _strlen(head->str);
		while (len)
			*(--s) = (head->str)[--len];
		if (stat(s, &st) == 0)
		{
/*			free(line); */
			printf("s is: %s\n", s);
			return (s);
		}
		head = head->next;
	}
/*	free(line); */
	return (NULL);
}
