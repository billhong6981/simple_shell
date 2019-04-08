#include "holberton.h"
/**
 * _strcmp - compaires two strings, subtracts ascii value if not the same
 * @s1: string 1
 * @s2: string 2
 *
 * Return: returns 0 if match, else subtracts s1 form s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
