#include "holberton.h"
/**
 * free_av - a function that free the vector have been allocated memories
 * @av: a vector array
 * Return: void
 */
void free_av(char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		free(av[i]);
		++i;
	}
/*	free(av);*/
}
