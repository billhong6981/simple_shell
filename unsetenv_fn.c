#include "holberton.h"
/**
 * unsetenv_fn - a function unset enviroment variable
 * @d: a string contains enviroment variable
 * @h: an unused variable
 * Return: returns NULL
 */
char *unsetenv_fn(char *d, __attribute__((unused)) list_t *h)
{
	int ret;

	ret = _unsetenv(d);
	if (ret == -1)
		write(2, "ERROR:unset is fail\n", 21);
	return (NULL);
}
