#include "holberton.h"
/**
 * ls_current_dir - a function displays current working directory
 * Return: returns the current working path
 */
char *ls_current_dir(void)
{
	char *value;

	value = _getenv("PWD");
	return (value);
}
