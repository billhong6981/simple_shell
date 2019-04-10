#include "holberton.h"
/*
 * get_current_dir - a function gets current working directory
 * @input:void
 * Return: current working directory string pointer
 */
size_t get_current_dir(char **dir, char *str)
{
	size_t i, size = 499;
	char *buf;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ':' && str[i + 1] == '/')
		{
			if ((buf = malloc(500)) == NULL)
				return (1);
			if ((*dir = getcwd(buf, size)) == NULL)
				return (1);
			return (0);
		}
	}
	return (1);
}
