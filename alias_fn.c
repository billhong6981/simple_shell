#include "holberton.h"
/**
 * alias_fn - a function lists the alias contents on teminal
 * @d: a alias name
 * @h: a unsied head pointer
 * Return: returns NULL
 */
char *alias_fn(char *d, __attribute__((unused)) list_t *h)
{
	char buf[1024], array[20];
	char *s = d, *str = "alias", *n = "/home/vagrant/.bash_aliases";
	int fd, i, bytes_read;

	fd = open(n, O_RDWR | O_CREAT | O_APPEND, S_IRWXU | S_IRGRP | S_IROTH);
	lseek(fd, 0, 0);
	bytes_read = read(fd, buf, 1023);
	if (*s == '\0' || s == NULL || *s == ' ')
	{
		write(1, buf, bytes_read);
		close(fd);
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		array[i] = str[i];
	}
	array[i] = ' ';
	for ( ; *s != '\0' && *s != ' ' && *s != '='; i++)
	{
		array[i] = *s++;
	}
	if (*s == '\0' || *s == ' ')
	{
		array[i] = '\0';
		write(1, array, _strlen(array));
		write(1, ":alias name not found\n", 22);
		close(fd);
		return (NULL);
	}
	if (*s == '=' && *(s + 1) == '\'')
	{
		lseek(fd, 0, 2);
		write(fd, d, _strlen(d));
		write(fd, "\n", 1);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (NULL);
}
