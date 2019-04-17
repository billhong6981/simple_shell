#include "holberton.h"
/**
 * exit_fn - a function exit the application
 * @h: a argument
 * @d: currently an unused atribute
 * Return: exit with 0 on success
 */
char *exit_fn(char *d, list_t *h)
{
	int n;

	n = (d == NULL) ? (0) : (_atoi(d));
	free_list(h);
	unsetenv("OLDPWD");
	write (1, "number:", 7);
	write (1, _itoa_fn(n), _strlen(_itoa_fn(n)));
	exit(n);
}
