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

	argv = conv_line(cmd, line);
	if (argv == NULL)
		return (1);
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("ERROR");
		return (1);
	}
	if (child_pid == 0)
	{
		ret = execve(cmd, argv, environ);
		if (ret == -1)
		{
			perror("ERROR");
			free(argv);
			return (1);
		}
	}
	else
	{
		wait(&status);
	}
	free(argv);
	return (0);
}
