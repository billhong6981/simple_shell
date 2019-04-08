#include "holberton.h"
/**
 *
 */
char **conv_line(char *cmd, char *line)
{
	char **av;
	char *str_dup, *token;
	int i, spac_num;

	for (i = 0, spac_num = 0; line[i] != '\0'; i++)
	{
		if (line[i] == ' ')
			spac_num++;
	}
	av = malloc((spac_num + 2) * sizeof(void *));
	str_dup = _strdup(line);
	token = strtok(str_dup, " ");
	av[0] = _strdup(cmd);
	for (i = 1; i <= spac_num; i++)
	{
		token = strtok(NULL, " ");
		av[i] = _strdup(token);

		printf("av[%d]:%s\n", i, av[i]);

	}
	av[i] = NULL;
	printf("av[0]:%s\n", av[0]);
	printf("av[%d]:%s\n", i, av[i]);

	free(str_dup);

	return (av);
}
