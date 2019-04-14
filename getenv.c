#include "holberton.h"
/**
 * _getenv - get enviroment variables
 * @env: env var to get
 * Return: current envirment variables, of specified type or null if fail
 */
char *_getenv(char *env)
{
	int i, count, j;
	char *pathcheck, *path, *value;
	char **ev;

	for (i = 0, count = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '=' && environ[i][j]; j++)
			;
		if (environ[i][j] == '=')
			count++;
	}
	ev = malloc(++count * sizeof(void *));
	for (i = 0; environ[i]; i++)
	{
		ev[i] = _strdup(environ[i]);
		pathcheck = strtok(ev[i], "=");
		if (!_strcmp(pathcheck, env))
		{
			path = strtok(NULL, "=");
			value = _strdup(path);
			for (j = 0; j <= i; j++)
				free(ev[j]);
			free(ev);
			return (value);
		}
	}
	free(ev);
	return (NULL);
}
