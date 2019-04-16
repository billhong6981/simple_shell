#include "holberton.h"
/**
 * _itoa_fn - a function converts integer to string
 * @n: a integer number
 *
 * Return: return a string
 */
char *_itoa_fn(int n)
{
	unsigned int temp1, temp2;
	int i = 1, j = 1, tens = 1, sign = 0;
	char *str;

	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	temp1 = temp2 = n;
	while (temp1 >= 10)
	{
		temp1 = temp1 / 10;
		i++;
	}
	str = (sign == 1) ? (malloc(i + 2)) : (malloc(i + 1));
	for (j = 1; j < i; j++)
		tens = tens * 10;
	if (sign == 1)
	{
		i = 1;
		str[0] = '-';
	}
	else
		i = 0;
	while (tens > 1)
	{
		str[i] = ((temp2 / tens) % 10 + '0');
		tens /= 10;
		i++;
	}
	str[i++] = (temp2 % 10 + '0');
	str[i] = '\0';
	return (str);
}
