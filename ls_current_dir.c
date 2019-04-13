#include "holberton.h"
/**
 * ls_current_dir - a function displays current working directory
 * @d: a path name with leading ':' character
 * Return: returns the current working path
 */
char *ls_current_dir(char *d)
{
	(void)d;
	char *value;
	value = getenv("PWD");
	return (value);
}
