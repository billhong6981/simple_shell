#include "holberton.h"
/**
 * _unsetenv - unset enviroment variables
 * @env: env var to get
 * Return: 0 on success, -1 if fail
 */
int _unsetenv(char *env)
{
	int i, count, j, flag = 0;
	char *pathcheck;
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
			for (j = 0; j <= i; j++)
				free(ev[j]);
			free(ev);
			flag = 1;
		}
		if (flag == 1)
			environ[i] = environ[i + 1];
	}
	if (flag == 1)
		return (0);
	for (j = 0; j < i; j++)
		free(ev[j]);
	free(ev);
	return (-1);
}
