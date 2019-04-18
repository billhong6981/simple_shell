#include "holberton.h"
/**
 * exit_fn - a function exit the application
 * @h: a argument
 * @d: currently an unused atribute
 * Return: exit with 0 on success
 */
char *exit_fn(char *d, list_t *h)
{
	int n, status;

	status = WEXITSTATUS(status);
	n = (d == NULL) ? (status) : (_atoi(d));
	free_list(h);
	exit(n);
}
