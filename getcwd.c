#include "holberton.h"
/**
 * _getcwd - get current working directory
 *
 * Return: the current working directory in string form
 */
char *_getcwd(void)
{
	char *dir = malloc(4096); /*max path size*/
	size_t dirsize = 4096;

	if (dir == NULL)
	{
		return (NULL);
	}
	getcwd(dir, dirsize);
	return (dir);
}
