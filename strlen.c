#include "holberton.h"

/**
 *_strlen - a function that returns the length of a string
 *@s: a pointer point to string
 *
 *Return: return a int number of the length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}
