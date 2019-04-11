#include "holberton.h"
#include <string.h>
/**
 *
 */
char *_getenv(char *env)
{
	extern char **environ;
	int i = 0;
	char *pathcheck, *path;
	while (environ[i])
	{
		pathcheck = strtok(environ[i], "=");
		if (!_strcmp(pathcheck, env))
		{
			printf("\n%s\n", pathcheck);
			path = strtok(NULL, "=");
			printf("path = %s\n", path);
			return (path);
		}
		i++;
	}
	return (NULL);
}
