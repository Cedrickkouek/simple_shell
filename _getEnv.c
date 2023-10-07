#include "main.h"

/**
 *_getenv - gets the environmental variable path
 *@name: is the name of the path
 *Return: env variable path
 */
char *_getenv(const char *name)
{
	size_t name_length;
	int i;

	if (name == NULL || _strlen(name) == 0)
	{
		return (NULL);
	}

	name_length = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(name, environ[i], name_length) == 0 &&
			environ[i][name_length] == '=')
		{
			return (&environ[i][name_length + 1]);
		}
	}

	return (ENV_NOT_FOUND);
}
