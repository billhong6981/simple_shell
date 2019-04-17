#include "holberton.h"
/**
 * ch_dir - a function changes current working directory
 * @old_dir:a directory change from
 * @value:a new directory change to
 * @flag: a boolien flag
 * Return: void
 */
int ch_dir(char *old_dir, char *value, int flag)
{
	int ret;
	char *current_dir = NULL;

	if (flag == 0)
	{
		ret = chdir(value);
		if (ret == 0)
		{
			setenv("OLDPWD", old_dir, 1);
			setenv("PWD", value, 1);
			free(old_dir);
			return (ret);
		}
	}
	if (flag == 1)
	{
		ret = chdir(value);
		if (ret == 0)
		{
			current_dir = _getcwd();
			_setenv("OLDPWD", old_dir, 1);
			_setenv("PWD", current_dir, 1);
			free(current_dir);
			free(old_dir);
			return (ret);
		}
	}
	free(old_dir);
	return (-1);
}
