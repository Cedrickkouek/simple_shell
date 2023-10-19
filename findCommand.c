#include "main.h"
/**
 *find_command - finds a file in the current PATH
 *@command: is the command to be found
 *Return: nothing(void)
 */
char *find_command(char *command)
{
	char *PATH, *p, *filepath, *path_copy;
	struct stat st;

	if (command == NULL)
	{
		fprintf(stderr, "Command not found\n");
		return (NULL);
	}
	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0 && S_ISREG(st.st_mode) &&
			(st.st_mode &S_IXUSR))
		{
			char *filepath = malloc(strlen(command) + 1);

			strcpy(filepath, command);
			return (filepath);
		}
		return (NULL);
	}
	PATH = _getenv("PATH");
	path_copy = _strdup(PATH);

	p = strtok(path_copy, ":");
	filepath = malloc(MAX_PATH_LENGTH + 1);
	while (p != NULL)
	{
		snprintf(filepath, MAX_PATH_LENGTH + 1, "%s/%s", p, command);
		if (stat(filepath, &st) == 0 && S_ISREG(st.st_mode) &&
			(st.st_mode &S_IXUSR))
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
