#include "holberton.h"
<<<<<<< HEAD
#include <string.h>
=======
>>>>>>> Developer
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
			path = strtok(NULL, "=");
			return (path);
		}
		i++;
	}
	return (NULL);
}
