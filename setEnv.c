#include "main.h"

int elsePart(const char *name, int overwrite,
const char *value, size_t value_len, size_t name_len);

/**
 *_setenv - enables to set a new env variable
 *@name: args1
 *@value: args2
 *@overwrite: args3
 *Return: an integer
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_var;
	size_t name_len, value_len;

	if (name == NULL || value == NULL)
	{
		printf("Invalid input.\n");
		return (-1);
	}

	name_len = strlen(name);
	value_len = strlen(value);

	env_var = getenv(name);

	if (env_var == NULL)
	{
		char *new_env_var = (char *) malloc(name_len + value_len + 2);

		if (new_env_var == NULL)
		{
			printf("Memory allocation failed.\n");
			return (-1);
		}

		snprintf(new_env_var, name_len + value_len + 2, "%s=%s", name, value);
		if (setenv(name, value, 1) != 0)
		{
			printf("Failed to add environment variable.\n");
			free(new_env_var);
			return (-1);
		}
		free(new_env_var);
	}
	else
	{
		return (elsePart(name, overwrite, value, value_len, name_len));
	}

	return (0);
}

int elsePart(const char *name, int overwrite,
const char *value, size_t value_len, size_t name_len)
{
	if (overwrite)
	{
		char *new_env_var = (char *) malloc(name_len + value_len + 2);

		if (new_env_var == NULL)
		{
			printf("Memory allocation failed.\n");
			return (-1);
		}

		snprintf(new_env_var, name_len + value_len + 2, "%s=%s", name, value);
		if (setenv(name, value, 1) != 0)
		{
			printf("Failed to update environment variable.\n");
			free(new_env_var);
			return (-1);
		}
		free(new_env_var);
	}
	else
	{
		printf("Environment variable '%s' already exists.\n", name);
		return (-1);
	}

	return (0);
}
