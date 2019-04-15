#include "holberton.h"
/**
 * exit_fn - a function exit the application
 * @h: a argument
 * Return: exit with 0 on success
 */
char *exit_fn(__attribute__((unused)) char *d, list_t *h)
{
	int n;

	n = (d == NULL) ? (0) : (_atoi(d));
	free_list(h);
	unsetenv("OLDPWD");
	printf("number:%d\n", n);
	exit(n);
}
