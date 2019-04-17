#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <stddef.h>
#include <assert.h>
#include <signal.h>
/* The following are global vars */
extern char **environ;
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;
/**
 * struct func - a data struct for builtin command and its function pointer
 * @str: a command string
 * @fn: a function pointer
 */
typedef struct func
{
	char *str;
	char *(*fn)();
} fn_types;
/**
 * struct string - a struct for the help cmd
 * @cmd: command to find help for
 * @help: the help command
 */
typedef struct string
{
	char *cmd;
	char *help;
} Strings;
/* The following are prototypes */
list_t *add_node(list_t **head, char *str);
void free_list(list_t *head);
char *_strdup(char *str);
int _strlen(char *s);
list_t *path_list(list_t **head);
char *search_file(list_t *head, char *str);
size_t print_list(list_t *h);
char *trun_space(char *str);
int exec_cmd(char *cmd, char *line);
void free_av(char **av);
char **conv_line(char *cmd, char *line);
int _strcmp(char *s1, char *s2);
size_t get_current_dir(char **dir, char *str);
char *_getcwd();
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *(*get_builtin_fn(char *s, char **d))(char *, list_t *);
char *change_dir(char *d, list_t *h);
char *_getenv(char *env);
char *ls_current_dir(void);
char *exit_fn(char *d, list_t *h);
int ch_dir(char *old_dir, char *value, int flag);
list_t *add_node_end(list_t **head, char *str);
int _atoi(char *s);
char *echo_fn(char *d, list_t *h);
char *_itoa_fn(int n);
char *setenv_fn(char *d, list_t *h);
char *unsetenv_fn(char *d, list_t *h);
int _unsetenv(char *env);
int _setenv(char *env, char *envval, int overwrite);
char *help_fn(char *d, list_t *h);

#endif
