#include "main.h"

/**
 *isEqual - checks if two strings are equal
 * @str1: args1
 * @str2: args2
 * Return: an integer
 */
int isEqual(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *) str1 - *(unsigned char *) str2);
}
