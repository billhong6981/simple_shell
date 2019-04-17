#include "holberton.h"
/**
 * _setenv_help - allocates memories for enviroment variables
 * @: input void
 * Return: return double pointer on success, NULL if fail
 */
char **_setenv_help(void)
{
	int i, count, j;
	char **ev;

	for (i = 0, count = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '=' && environ[i][j]; j++)
			;
		if (environ[i][j] == '=')
			count++;
	}
	ev = malloc(++count * sizeof(void *));
	if (ev == NULL)
		return (NULL);
	return (ev);
}
