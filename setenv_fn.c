#include "holberton.h"
/**
 * setenv_fn - a function changes the enviroment
 * @d: a string contains enviroment variable and desired to change value
 * Return: returns NULL
 */
char *setenv_fn(char *d, __attribute__((unused)) list_t *h)
{
	char *value, *var;
	int ret;

	var = strtok(d, " ");
	value = strtok(NULL, " ");
	ret = setenv(var, value, 1);
	if (ret == -1)
		write(2, "ERROR:update is fail\n", 21);
	return (NULL);
}
