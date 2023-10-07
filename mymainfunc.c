#include "main.h"

/**
 *parse_line - passes a line to execute function
 *@line: arg1
 *@args: arg2
 *Return: nothing
 */

void parse_line(char *line, char **args)
{
	char *token = strtok(line, " \n");
	int i = 0;

	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}

	args[i] = NULL;
}

/**
 *execute_command - executes a command
 *@args: arg1
 *Return: nothing
 */
void execute_command(char **args)
{
	pid_t pid;
	char *command_path;

	if (isEqual(args[0], "exit") == 0)
	{
		exit(0);
	}

	command_path = find_command(args[0]);
	if (command_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork Failed");
		free(command_path);
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(command_path, args, environ) < 0)
		{
			perror(args[0]);
			free(command_path);
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
	free(command_path);
}

/**
 *main -  Is a super simple shell program
 *Return: An integer 0
 */
int main(void)
{
	char *args[MAX_LINE / 2 + 1];
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	int interactive = isatty(STDIN_FILENO);

	do {
		if (interactive)
		{
			printf("$ ");
			fflush(stdout);
		}

		read = _getline(&line, &len, stdin);
		if (read == -1)
		{
			break;
		}

		parse_line(line, args);
		if (args[0] != NULL)
		{
			execute_command(args);
		}
	} while (interactive);

	return (0);
}
