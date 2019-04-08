#include "holberton.h"
/**
 * exec_cmd - a function that executes the command it takes from arguments
 * @cmd: the command or executable file
 * @line: the argument get from CLI input
 * Return: return 0 on success, 1 if fail
 */
int exec_cmd(char *cmd, char *line)
{
	int ret, status;
	char **argv;
	pid_t child_pid;
	char *const env[] = {"HOME=/usr/home", "PATH=/bin:/sbin", NULL};

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("ERROR");
		return (1);
	}
	if (child_pid == 0)
	{
		argv = conv_line(cmd, line);
		if (argv == NULL)
			return (1);
		ret = execve(cmd, argv, env);
		if (ret == -1)
		{
			perror("ERROR");
			free(argv);
/*			free_av(argv); */
			return (1);
		}
	}
	else
	{
		wait(&status);
	}
/*	free_av(argv);*/
/*	free(argv);*/
	return (0);
}
