#include "holberton.h"
/**
 * _strdup - a function that copies a string into a new buffer
 * @str: a pointer point to the string
 *
 * Return: pointer point to the buffer
 */

char *_strdup(char *str)
{
	char *p;
	unsigned int len, j;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++)
		;
	len++;
	if (len < 1)
		return (NULL);
	p = malloc(len + 1);
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	for (j = 0; j < len; j++)
		p[j] = str[j];
	p[j] = '\0';
	return (p);
}
