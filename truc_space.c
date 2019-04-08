#include "holberton.h"
/**
 * trun_space - a function that deletes the leading space(se)
 * @str: a string
 * Return: return a string
 */
char *trun_space(char *str)
{
	char *str1;
	static char buffer[1000];
	int len;
	int flag = 0;

	str1 = &buffer[999];
	*str1 = '\0';
	len = _strlen(str);
	while (len)
	{
		--len;
		if (str[len] != ' ' && str[len] != '\n' && flag == 0)
		{
			*(--str1) = str[len];
			flag = 1;
			continue;
		}
		if (str[len] == ' ' || str[len] == '\n')
			continue;
		if (str[len] != ' ' && str[len + 1] == ' ')
		{
			*(--str1) = ' ';
			*(--str1) = str[len];
		}
		else
		{
			*(--str1) = str[len];
		}
	}
	return ((flag == 0) ? (NULL) : (str1));
}
