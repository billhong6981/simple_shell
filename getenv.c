#include "holberton.h"
/**
 * _getenv - get enviroment variables
 * @env: env var to get
 * Return: current envirment variables, of specified type or null if fail
 */
char *_getenv(char *env)
{
	int i = 0;
	char *pathcheck, *path;

	while (environ[i])
	{
		pathcheck = strtok(environ[i], "=");
		if (!_strcmp(pathcheck, env))
		{
			path = strtok(NULL, "=");
			return (path);
		}
		i++;
	}
	return (NULL);
}
