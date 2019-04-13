#include "holberton.h"
/**
 * _getcwd - gets the current working dir
 * Return: the current working dir
 */
char *_getcwd(void)
{
	char *dir = malloc(1024); /*max path size*/
	size_t dirsize = 1024;

	if (dir == NULL)
	{
		return (NULL);
	}
	getcwd(dir, dirsize);
	return (dir);
}
