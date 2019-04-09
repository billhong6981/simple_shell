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
	char *cmd, *dir = NULL, *new_line, *line = NULL;

	path_list(&head);
	while (1)
	{
		dir = _getcwd();
		write(1, dir, _strlen(dir));
		write(1, "$ ", 2);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		ext = _strcmp(line, "exit\n");
		if (ext == 0)
		{
			free_list(head);
			free(line);
			exit(0);
		}
		printf("%s", line);
		new_line = trun_space(line);
		printf("newline:%s\n", new_line);
		if (new_line == NULL)
			continue;
		cmd = search_file(head, new_line);
		if (cmd == NULL)
		{
			write(1, new_line, _strlen(new_line));
			write(1, ": command not found\n", 20);
		}
		else
			exec_cmd(cmd, new_line);
	}
	free(dir);
	free_list(head);
	free(line);
	return (0);
}
