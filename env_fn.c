#include "holberton.h"
/**
 * env_f - prints enviroment variables
 * @d: a string
 * @h: linked list head pointer
 * Return: return NULL
 */
char *env_f(__attribute__((unused)) char *d, __attribute__((unused)) list_t *h)
{
	int i;

	if (environ == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}
	return (NULL);
}
