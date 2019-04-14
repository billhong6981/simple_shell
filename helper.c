#include "holberton.h"
/**
 * get_builtin_fn - a function help to found builtin function
 * @s: a input command string
 * @d: command arguments
 * Return: return a function pointer if found, otherwise NULL
 */
char *(*get_builtin_fn(char *s, char **d))(char *, list_t *)
{
	int i, j;
	char *cmd = NULL;
	static char array[100];
	fn_types builtin_fn[] = {
		{"cd", change_dir},
		{"exit", exit_fn},
		{NULL, NULL} };

	*d = &array[0];
	for (i = 0; i < 100; i++)
		(*d)[i] = '\0';
	if (s == NULL)
		return (NULL);
	cmd = malloc((_strlen(s) + 1));
	if (cmd == NULL)
		return (NULL);
	for (i = 0; s[i] != ' ' && s[i] != '\0'; i++)
		cmd[i] = s[i];
	cmd[i] = '\0';
	if (s[i] != '\0')
	{
		++i;
		for (j = 0; s[i] != ' ' && s[i] != '\0'; i++, j++)
			(*d)[j] = s[i];
	}
	for (i = 0; builtin_fn[i].str; i++)
	{
		if (_strcmp(cmd, builtin_fn[i].str) == 0)
		{
			free(cmd);
			return (builtin_fn[i].fn);
		}
	}
	free(cmd);
	return (NULL);
}
