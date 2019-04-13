#include "holberton.h"
/**
 * get_current_dir - checks if the dir has a :/
 * @dir: dir to check
 * @str: string to check
 * Return: 0 if success, 1 if fail
 */
size_t get_current_dir(char **dir, char *str)
{
	size_t i, size = 499;
	char *buf;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ':' && str[i + 1] == '/')
		{
			buf = malloc(500);
			if (buf == NULL)
				return (1);
			*dir = getcwd(buf, size);
			if (*dir == NULL)
				return (1);
			return (0);
		}
	}
	return (1);
}
