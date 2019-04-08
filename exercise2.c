#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *
 */
int main(void)
{
	int i, ret, status;
	pid_t child_pid, mychild_pid, my_pid;
	char *argv[] = {"/bin/ls", "-l", "/home", NULL};
	char *envp[] = {"PATH=/bin/", "HOME=/usr/home", NULL};

	my_pid = getpid();
	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("ERROR");
			exit(1);
		}
		if (child_pid == 0)
			sleep(3);
		else
		{
			wait(&status);
			ret = execve(argv[0], argv, envp);
			if (ret == -1)
			{
				perror("ERROR");
				exit(1);
			}
		}
		mychild_pid = getpid();
		printf("Before wait()/mypid:%u childpid:%u mychildpid:%u\n", my_pid, child_pid, mychild_pid);

		printf("After wait()/mypid:%u childpid:%u mychildpid:%u\n", my_pid, child_pid, mychild_pid);
	}
	exit(0);
}
