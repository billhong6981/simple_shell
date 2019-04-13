#include "holberton.h"
/**
 * ch_dir - a function changes current working directory
 * @old_dir:a directory change from
 * @value:a new directory change to
 * Return: void
 */
int ch_dir(char *old_dir, char *value, int flag)
{
	int ret;
	char *current_dir = NULL;

	if (flag == 0)
	{
		if ((ret = chdir(value)) == 0)
		{
			setenv("OLDPWD", old_dir, 1);
			setenv("PWD", value, 1);
			free(old_dir);
			return (ret);
		}
	}
	if (flag == 1)
	{
		if ((ret = chdir(value)) == 0)
		{
			current_dir = _getcwd();
			setenv("OLDPWD", old_dir, 1);
			setenv("PWD", current_dir, 1);
			free(current_dir);
			free(old_dir);
			return (ret);
		}
	}
	free(old_dir);
	return (-1);
}
