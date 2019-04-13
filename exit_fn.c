#include "holberton.h"
/**
 * exit_fn - a function exit the application
 * @d: a argument
 * Return: exit with 0 on success
 */
char *exit_fn(char *d)
{
	(void)d;
	unsetenv("OLDPWD");
	exit(0);
}
