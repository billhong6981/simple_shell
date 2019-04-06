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
/* The following are prototypes */
list_t *add_node(list_t **head, char *str);
void free_list(list_t *head);
char *_strdup(char *str);
int _strlen(char *s);
list_t *path_list(list_t **head);
char *search_file(list_t *head, char *str);
size_t print_list(list_t *h);
char *trun_space(char *line);

#endif
