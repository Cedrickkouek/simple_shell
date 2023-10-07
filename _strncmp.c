#include "main.h"
/**
* _strncmp -  compares two string according to a number of character
* @str1: string 1
* @str2: string 2
* @n: number
* Return: an integer;
*/
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}

		if (str1[i] == '\0')
		{
			return (0);
		}
	}

	return (0);
}
