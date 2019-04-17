#include "holberton.h"
/**
 * _setenv - set enviroment variables
 * @env: env var
 * @envval: env value desired to set
 * @overwrite: 1 overwrite, 0 unchange
 * Return: 0 on success, -1 if fail
 */
int _setenv(char *env, char *envval, int overwrite)
{
	int i, j;
	char *pathcheck, **ev;

	if (overwrite == 0)
		return (0);
	for (i = 0; env[i] != '\0'; i++)
	{
		if (env[i] == '=')
			return (-1);
	}
	ev = _setenv_help();
	for (i = 0; environ[i]; i++)
	{
		ev[i] = _strdup(environ[i]);
		pathcheck = strtok(ev[i], "=");
		if (!_strcmp(pathcheck, env))
		{
			for (j = 0; j <= i; j++)
				free(ev[j]);
			free(ev);
			for (j = 0; env[j] != '\0'; j++)
				environ[i][j] = env[j];
			environ[i][j++] = '=';
			for (; *envval != '\0'; j++)
				environ[i][j] = *(envval++);
			environ[i][j] = *envval;
			return (0);
		}
	}
	for (j = 0; j < i; j++)
		free(ev[j]);
	free(ev);
	for (j = 0; env[j] != '\0'; j++)
		environ[i][j] = env[j];
	environ[i][j++] = '=';
	for (; *envval != '\0'; j++)
		environ[i][j] = *(envval++);
	environ[i][j] = *envval;
	environ[++i] = NULL;
	return (0);
}
