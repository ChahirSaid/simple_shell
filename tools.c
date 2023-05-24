#include "shell.h"

/**
 * _isdigit - checks for a digit (0 through 9).
 * @c: character to check.
 * Return: 1 True, 0 False.
 */

int _isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

/**
 * is_number - check if string can be converted to a number.
 * @n: string.
 * Return:
 * 1 number
 * 0 not number
 */

int is_number(char *n)
{
	while (*n != '\0')
	{
		if (_isdigit(*n) == 0)
			return (0);
		n++;
	}
	return (1);
}

/**
 * _atoi -  convert a string to an integer.
 * @s: string to convert
 * Return: converted value of s
 */

int _atoi(char *s)
{
	unsigned int number = 0, max = 1;
	int len = _strlen(s), i, minus;
	/* get sign and number length */
	minus = 1, i = 0;
	for (i = 0; i <= len; i++)
	{
		if (*(s + i) == '-')
			minus *= -1;
		if (*(s + i) >= 48 && *(s + i) <= 57)
		{
			i++;
			while (*(s + i) >= 48 && *(s + i) <= 57)
			{
				max *= 10;
				i++;
			}
			break;
		}
	}
	/* get number */
	for (i = 0; i <= len; i++)
	{
		if (*(s + i) >= 48 && *(s + i) <= 57)
		{
			while (*(s + i) >= 48 && *(s + i) <= 57)
			{
				number += (*(s + i) - '0') * max;
				max /= 10;
				i++;
			}
			break;
		}
	}
	number *= minus;
	return (number);
}
