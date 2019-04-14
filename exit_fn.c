#include "holberton.h"
/**
 * exit_fn - a function exit the application
 * @h: a argument
 * Return: exit with 0 on success
 */
char *exit_fn(__attribute__((unused)) char *d, list_t *h)
{
	free_list(h);
	unsetenv("OLDPWD");
	exit(0);
}
