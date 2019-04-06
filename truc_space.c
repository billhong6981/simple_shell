#include "holberton.h"
/**
 * trun_space - a function that deletes the leading space(se)
 * @line: a string
 * Return: return a string
 */
char *trun_space(char *line)
{
	char *s = NULL;
	int i = 0;

	while (line[i] == ' ' && line[i + 1] != '\0')
	{
		i++;
	}
	s = &line[i];
	return (s);
}
