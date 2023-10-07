#include "main.h"

/**
 *_strdup - create duplicate copy of a string
 *@str: string
 *Return: a string
 */
char *_strdup(const char *str)
{
	size_t len = _strlen(str) + 1;
	char *duplicate = malloc(len);

	if (duplicate != NULL)
	{
		_memcpy(duplicate, str, len);
	}

	return (duplicate);
}
