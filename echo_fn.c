#include "holberton.h"
/**
 * echo_fn - a function displays the varialble contents on teminal
 * @d: a directory name desired to change
 * @h: a unsied head pointer
 * Return: returns the contents of variable
 */
char *echo_fn(char *d, __attribute__((unused)) list_t *h)
{
	char *value, *str = NULL;
	pid_t mypid;
	int len;

	if (d[0] == '$')
	{
		str = &d[1];
		value = getenv(str);
		if (value != NULL)
		{
			write(1, value, _strlen(value));
			write(1, "\n", 1);
			return (NULL);
		}
		if (d[1] == '$' && d[2] == '\0')
		{
			mypid = getpid();
			str = _itoa_fn(mypid);
			write(1, str, _strlen(str));
			write(1, "\n", 1);
			free(str);
			return (NULL);
		}
		if (d[1] == '?' && d[2] == '\0')
		{
			write(1, "0\n", 2);
			return (NULL);
		}
	}
	if (d != NULL)
	{
		len = _strlen(d);
		write(1, d, len);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (NULL);
}
