#include "main.h"

/**
* _strlen -  returns the length of a string
* @str: the string whose length is to be returned
* Return: the length of the string
*/

size_t _strlen(const char *str)
{
	size_t length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}

	return (length);
}
