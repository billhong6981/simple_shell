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
	char *cmd;
	char *line = NULL;

	path_list(&head);
/*	print_list(head);  */
	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		printf("%s", line);

/*		if (line[0] == ' ')
			line = trun_space(line);
*/
		cmd = search_file(head, line);
		printf("cmd:%s\n", cmd);

/*		if (cmd == NULL)
			printf("NOT FOUND FILE\n");
		else
		printf("FOUND FILE:%s\n", cmd);  */

	}
	free(line);
	free_list(head);
	return (0);
}
