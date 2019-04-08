#include "holberton.h"
/**
 * conv_line - converts a line to a command able to be run through execve
 * @cmd: command entered
 * @line: argument entered for cmd
 *
 * Return: a array of strings to be passed to execve
 */
char **conv_line(char *cmd, char *line)
{
	char **av;
	int i, spac_num;

	for (i = 0, spac_num = 0; line[i] != '\0'; i++)
	{
		if (line[i] == ' ')
			spac_num++;
	}
	av = malloc((spac_num + 2) * sizeof(void *));
/*	str_dup = _strdup(line);
	token = strtok(str_dup, " ");
	av[0] = _strdup(cmd);*/
	strtok(line, " ");
	av[0] = cmd;
	for (i = 1; i <= spac_num; i++)
	{
		av[i] = strtok(NULL, " ");
/*		av[i] = token; _strdup(token);*/
	}
	av[i] = NULL;
/*	free(str_dup);*/
	return (av);
}
