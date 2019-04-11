#include "holberton.h"
/**
 * get_builtin_fn - a function help to found builtin function
 * @s: a input command string
 * @d: command arguments
 * Return: return a function pointer if found, otherwise NULL
 */
char *(*get_builtin_fn(char *s, char **d))(char *)
{
	int i, j;
	char *cmd = NULL;
	fn_types builtin_fn[] = {
		{"cd", change_dir},
		{NULL, NULL} };

	cmd = malloc((_strlen(s) + 2));
	if (cmd == NULL)
		return (NULL);
	for (i = 0; s[i] != ' ' && s[i] != '\0'; i++)
		cmd[i] = s[i];
	cmd[i] = '\0';
	if (s[i] == '\0')
		(*d) = NULL;
	else
	{
		(*d) = &cmd[++i];
		for (j = 0; s[i] != ' ' && s[i] != '\0'; i++, j++)
			(*d)[j] = s[i];
		(*d)[j] = '\0';
	}
	for (i = 0; builtin_fn[i].str; i++)
	{
		if (_strcmp(cmd, builtin_fn[i].str) == 0)
			return (builtin_fn[i].fn);
	}
	return (NULL);
}
