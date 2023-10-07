#include "main.h"
/**
* _memcpy - copies a block of memory to another place
* @dest: destination
* @src: source
* @n: number
* Return: nothing
*/
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *cdest = (char *) dest;
	const char *csrc = (const char *) src;

	size_t i;

	for (i = 0; i < n; i++)
	{
		cdest[i] = csrc[i];
	}

	return (dest);
}
