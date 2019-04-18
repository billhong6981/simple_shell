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
	fn_types builtin_fn[9];
	char *cmd = NULL;
	static char array[300];

	builtin_fn[0].str = "cd";
	builtin_fn[0].fn = change_dir;
	builtin_fn[1].str = "echo";
	builtin_fn[1].fn = echo_fn;
	builtin_fn[2].str = "exit";
	builtin_fn[2].fn = exit_fn;
	builtin_fn[3].str = "setenv";
	builtin_fn[3].fn = setenv_fn;
	builtin_fn[4].str = "unsetenv";
	builtin_fn[4].fn = unsetenv_fn;
	builtin_fn[5].str = "help";
	builtin_fn[5].fn = help_fn;
	builtin_fn[6].str = "alias";
	builtin_fn[6].fn = alias_fn;
	builtin_fn[7].str = "env";
	builtin_fn[7].fn = env_f;
	builtin_fn[8].str = NULL;
	builtin_fn[8].fn = NULL;
	*d = &array[0];
	for (i = 0; i < 300; i++)
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
		for (j = 0; s[i] != '\0' && s[i] != '#'; i++, j++)
			(*d)[j] = s[i];
		(*d)[j] = '\0';
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
