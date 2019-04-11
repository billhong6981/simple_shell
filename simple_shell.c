#include "holberton.h"
/**
 * main - a function works like the simple shell
 * @: input void
 * Return: 0 on success, 1 if fail
 */
int main(void)
{
	list_t *head = NULL;
	ssize_t nread;
	size_t len = 0, ext = 1;
	char *cmd, *av1 = NULL, *dir = NULL, *new_line, *line = NULL;
	char *(*found_builtin)(char *);

	path_list(&head);
	while (1)
	{
		dir = _getcwd();
		write(1, dir, _strlen(dir));
		free(dir);
		write(1, "$ ", 2);
		if ((_get_line(&line, &len, stdin)) == -1)
			break;
		if ((_strcmp(line, "exit\n")) == 0)
		{
			free_list(head);
			free(line);
			exit(0);
		}
		if ((new_line = trun_space(line)) == NULL)
			continue;
		found_builtin = get_builtin_fn(new_line, &av1);
		if (found_builtin != NULL)
		{
			found_builtin(av1);
			if (av1 != NULL)
				free(av1);
			continue;
		}
		if (av1 != NULL)
			free(av1);
		if ((cmd = search_file(head, new_line)) == NULL)
		{
			write(1, new_line, _strlen(new_line));
			write(1, ": command not found\n", 20);
		}
		else
			exec_cmd(cmd, new_line);
	}
	free_list(head);
	free(line);
	return (0);
}
