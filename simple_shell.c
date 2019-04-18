#include "holberton.h"
/**
 * main - a function works like the simple shell
 * @: input void
 * Return: 0 on success, 1 if fail
 */
int main(void)
{
	list_t *head = NULL;
	size_t len = 0;
	char *cmd, *dir, *av1 = NULL, *new_line, *line = NULL;
	char *(*found_builtin)(char *, list_t *);

	path_list(&head);
	while (1)
	{
		if (isatty(0))
		{
			dir = _getcwd();
			write(1, dir, _strlen(dir));
			write(1, "$ ", 2);
			free(dir);
		}
		if ((getline(&line, &len, stdin)) == -1)
		{
			break;
		}
		new_line = trun_space(line);
		if (new_line == NULL)
			continue;
		found_builtin = get_builtin_fn(new_line, &av1);
		if (found_builtin != NULL)
		{
			found_builtin(av1, head);
			continue;
		}
		cmd = search_file(head, new_line);
		if (cmd == NULL)
		{
			write(1, "1: ", 3);
			write(1, new_line, _strlen(new_line));
			write(1, ": not found\n", 12);
		}
		else
			exec_cmd(cmd, new_line);
	}
	free(line);
	free_list(head);
	return (0);
}
