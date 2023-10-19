#include "main.h"
/**
 *find_command - finds a file in the current PATH
 *@command: is the command to be found
 *Return: nothing(void)
 */
char *find_command(char *command)
{
	struct stat st;

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0 && S_ISREG(st.st_mode) &&
			(st.st_mode & S_IXUSR))
		{
			char *filepath = malloc(strlen(command) + 1);

			strcpy(filepath, command);
			return (filepath);
		}

		return (NULL);
	}

	return (NULL);
}

