#include "holberton.h"
/**
 * _realloc - a function that reallocates block of memory using malloc and free
 * @ptr: a pointer point to old block of memory
 * @old_size: old size of the block of memory
 * @new_size: new size of the block of memory
 *
 * Return: return a pointer point to new block of memory, or NULL if fail
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *block, *ptr1;

	if (new_size <= old_size)
		return (ptr);
	if (ptr == NULL)
	{
		block = malloc(new_size);
		return (block);
	}
	block = malloc(sizeof(*block) * new_size);
	if (block == NULL)
		return (NULL);
	ptr1 = ptr;
	for (i = 0; i < old_size; i++)
		block[i] = ptr1[i];
	free(ptr);
	return (block);
}
