#include "holberton.h"
/**
 * help_fn - a function displays a builtin command informations
 * @d: a builtin command name
 * @h: a unused head pointer
 * Return: returns NULL
 */
char *help_fn(char *d, __attribute__((unused)) list_t *h)
{
	int i;
	Strings helper[7];

	helper[0].cmd = "cd";
	helper[0].x = "cd: cd [dir]...\nChange the shell working directory.\n";
	helper[1].cmd = "echo";
	helper[1].x = "echo: echo [$arg]...\nWrite arguments to the std output\n";
	helper[2].cmd = "exit";
	helper[2].x = "exit: exit(n)\nExit the shell with status of n\n";
	helper[3].cmd = "setenv";
	helper[3].x = "setenv: setenv VARIABLE value\nSet env VAR with value\n";
	helper[4].cmd = "unsetenv";
	helper[4].x = "unsetenv: unsetenv VARIABLE\nUnset enviroment VAR\n";
	helper[5].cmd = "help";
	helper[5].x = "help: help [cmd]\nDisplay info about builtin command\n";
	helper[6].cmd = NULL;
	helper[6].x = NULL;
	for (i = 0; helper[i].cmd; i++)
	{
		if (_strcmp(d, helper[i].cmd) == 0)
		{
			write(1, helper[i].x, _strlen(helper[i].x));
			return (NULL);
		}
	}
	write(1, "Please use man to display more informations\n", 44);
	return (NULL);
}
