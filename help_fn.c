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
	char *cd_h = "cd: cd [dir]...\nChange the shell working directory.\n";
	char *e_h = "echo: echo [$arg]...\nWrite arguments to the std output\n";
	char *ex_h = "exit: exit(n)\nExit the shell with status of n\n";
	char *set_h = "setenv: setenv VARIABLE value\nSet env VAR with value\n";
	char *unset_h = "unsetenv: unsetenv VARIABLE\nUnset enviroment VAR\n";
	char *help_h = "help: help [cmd]\nDisplay info about builtin command\n";
	Strings helper[] = {
		{"cd", cd_h},
		{"echo", e_h},
		{"exit", ex_h},
		{"setenv", set_h},
		{"unsetenv", unset_h},
		{"help", help_h},
		{NULL, NULL} };

	for (i = 0; helper[i].cmd; i++)
	{
		printf("d:%s, cmd:%s\n", d, helper[i].cmd);
		if (_strcmp(d, helper[i].cmd) == 0)
		{
			write(1, helper[i].help, _strlen(helper[i].help));
			return (NULL);
		}
	}
	write(1, "Please use man to display more informations\n", 44);
	return (NULL);
}
