#include "holberton.h"
/**
 * _strstr - a function locates a substring
 * @haystack: string to be searched
 * @needle: substring to be found
 * Return: pointer to substring or NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *a, *b;

	b = needle;
	if (!*b)
		return (haystack);
	for ( ; *haystack != 0; haystack++)
	{
		if (*haystack != *b)
			continue;
		a = haystack;
		while (1)
		{
			if (!*b)
				return (haystack);
			if (*a++ != *b++)
				break;
		}
		b = needle;
	}
	return (NULL);
}
