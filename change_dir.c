#include "holberton.h"
/**
 *
 */
char *change_dir(char *d)
{
	int ret;
	char *value, *old_dir;

	old_dir = _getcwd();
	if (d == NULL || _strcmp(d, "~") == 0 || _strcmp(d, "$HOME") == 0)
	{
		value = getenv("HOME");
		ret = chdir(value);
		if (ret == 0)
		{
			setenv("OLDPWD", old_dir, 1);
			setenv("PWD", value, 1);
		}
		free(old_dir);
		return (value);
	}
	if (_strcmp(d, "-") == 0)
	{
		value = getenv("OLDPWD");
		ret = chdir(value);
		if (ret == 0)
                {
                        setenv("OLDPWD", old_dir, 1);
                        setenv("PWD", value, 1);
                }
		free(old_dir);
                return (value);
	}
	ret = chdir(d);
	if (ret == 0)
	{
		setenv("OLDPWD", old_dir, 1);
		setenv("PWD", d, 1);
	}
	free(old_dir);
	return (d);
}
