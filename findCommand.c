#include "main.h"

/**
 *find_command - finds a file in the current PATH
 *@command: is the command to be found
 *Return: nothing(void)
 */
char *find_command(char *command)
{
	char *PATH = _getenv("PATH");
	char *p;
	char *filepath;
	char *path_copy = _strdup(PATH);
	struct stat st;

	if (strchr(command, '/') != NULL)
	{
		struct stat st;

		if (stat(command, &st) == 0 && S_ISREG(st.st_mode)
				&& (st.st_mode & S_IXUSR))
		{
			char *filepath = malloc(strlen(command) + 1);

			strcpy(filepath, command);
			return (filepath);
		}

		return (NULL);
	}

	p = strtok(path_copy, ":");
	filepath = malloc(MAX_PATH_LENGTH + 1);

	while (p != NULL)
	{
		snprintf(filepath, MAX_PATH_LENGTH + 1, "%s/%s", p, command);
		if (stat(filepath, &st) == 0 && S_ISREG(st.st_mode)
				&& (st.st_mode & S_IXUSR))
		{
			return (filepath);
		}

		p = strtok(NULL, ":");
		filepath[MAX_PATH_LENGTH] = '\0';
	}

	free(path_copy);
	free(filepath);
	return (NULL);
}
