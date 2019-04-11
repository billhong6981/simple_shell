#include "holberton.h"
/**
 * change_dir - a function changes the working directory
 * @d: a directory name desired to change
 * Return: return the name of current working directory
 */
char *change_dir(char *d)
{
	int ret, len;
	char *value, *old_dir;

	old_dir = _getcwd();
	if (d == NULL || _strcmp(d, "~") == 0 || _strcmp(d, "$HOME") == 0)
	{
		value = _getenv("HOME");
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
		value = _getenv("OLDPWD");
		ret = chdir(value);
		if (ret == 0)
                {
                        setenv("OLDPWD", old_dir, 1);
                        setenv("PWD", value, 1);
                }
		free(old_dir);
                return (value);
	}
	if ((_strcmp(d, ".")) == 0 || (_strcmp(d, "./")) == 0)
	{
		value = _getenv("PWD");
	        free(old_dir);
		return (value);
	}
	if ((_strcmp(d, "..")) == 0)
	{
		value = _getenv("PWD");
		len = _strlen(value);
		while (len)
		{
			if (value[--len] == '/')
				value[len] = '\0';
		}
		d = value;
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
