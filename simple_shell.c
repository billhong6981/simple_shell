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
	char *cmd, *new_line, *line = NULL;

	path_list(&head);
	while (1)
	{
		printf("$ ");
		if ((nread = getline(&line, &len, stdin)) == -1)
			break;
		ext = _strcmp(line, "exit\n");
		if (ext == 0)
		{
			free_list(head);
			free(line);
			exit(0);
		}
		printf("%s", line);
		if ((new_line = trun_space(line)) == NULL)
			continue;
		if ((cmd = search_file(head, new_line)) == NULL)
			printf("%s:NO such file or directory\n", cmd);
		else
			exec_cmd(cmd, new_line);
	}
	free_list(head);
	free(line);
	return (0);
}
