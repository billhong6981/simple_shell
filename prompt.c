#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - a function gets arguments from stdin and display it
 *
 * Return: 0 on success, -1 if fail
 */
int main(void)
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		printf("%s", line);
	}
	free(line);
	return (0);
}
