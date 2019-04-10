#include "holberton.h"

/**
 *
 */
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream)
{
	size_t maxchar = 1024, i = 0;
	int c;

	(*lineptr) = malloc(maxchar * sizeof(char));
	if ((*lineptr) == NULL)
		return (*n = -1);
	while (1)
	{
		c = fgetc(stream);
		if ((i >= maxchar - 2) || c == EOF || c == '\n')
			break;
		(*lineptr)[i++] = c;
	}
	if (i >= maxchar -2)
	{
		maxchar += maxchar;
		(*lineptr) = _realloc((*lineptr), i, maxchar);
		if ((*lineptr) == NULL)
			return (*n = -1);
	}
	else
	{
		(*lineptr)[i] = '\n';
		(*lineptr)[++i] = '\0';
	}
	return (*n = i);
}
