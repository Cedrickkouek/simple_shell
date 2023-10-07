#include "main.h"
/**
 *_getline - reads the users important
 *@n: arg1
 *@lineptr: arg2
 *@stream: arg3
 *Return: an integer
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buffer_size;
	size_t line_length;
	char *new_lineptr;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	buffer_size = MAX_BUFFER_SIZE;
	line_length = 0;

	*lineptr = (char *) malloc(buffer_size);
	if (*lineptr == NULL)
	{
		return (-1);
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (line_length >= buffer_size - 1)
		{
			buffer_size *= 2;
			new_lineptr = (char *) realloc(*lineptr, buffer_size);
			if (new_lineptr == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = new_lineptr;
		}
		(*lineptr)[line_length++] = c;

		if (c == '\n')
		{
			break;
		}
	}
	(*lineptr)[line_length] = '\0';
	*n = line_length;
	return (line_length);
}
