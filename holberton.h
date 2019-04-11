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
char *_getcwd(void);
char *_getenv(void);
size_t print_list(list_t *h);
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *(*get_builtin_fn(char *s, char **d))(char *);
char *change_dir(char *d);

#endif
