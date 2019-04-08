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
	size_t len = 0;
	char *cmd, *new_line, *line = NULL;

	path_list(&head);
	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		printf("%s", line);
		new_line = trun_space(line);
		printf("newline:%s\n", new_line);
		if (new_line == NULL)
			continue;
		cmd = search_file(head, new_line);
		if (cmd == NULL)
			printf("NOT FOUND FILE\n");
		else
		{
			exec_cmd(cmd, new_line);
		}
	}
	free(line);
	free_list(head);
	return (0);
}
