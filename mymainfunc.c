#include "main.h"
/**
 * checkEnv - checks the env variable
 * @str:arg1
 * @path:arg2
 * Return: nothing(void)
*/
void checkEnv(char *str, char *path)
{
	if (isEqual(str, "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}

		_setenv("PWD", path, 1);
		return;
	}
}

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

void cmd_command(char **args)
{
	if (isEqual(args[0], "cd") == 0)
	{
		if (args[1] == NULL || isEqual(args[1], "~") == 0)
		{
			chdir(_getenv("HOME"));
		}
		else if (isEqual(args[1], "-") == 0)
		{
			chdir(_getenv("OLDPWD"));
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("chdir");
			}
		}
		_setenv("PWD", getcwd(NULL, 0), 1);
		return;
	}
}

/**
 *execute_command - executes a command
 *@args: arg1
 *Return: nothing
 */
void execute_command(char **args)
{
	pid_t pid;
	char *cmd;

	if (isEqual(args[0], "exit") == 0)
	{
		exit(0);
	}

	if(isEqual(args[0], "env"))
	{
		char *en = _getenv("PATH");
		printf("%s\n", en);
	}
	cmd_command(args);
	if (args[0] == NULL)
	{
		return;
	}
	cmd = find_command(args[0]);
	if (cmd == NULL)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork Failed");
		exit(1);
	}
	else if (pid == 0)
	{
		execve(cmd, args, environ);
		perror(cmd);
		exit(1);
	}
	else
	{
		wait(NULL);
	}
	free(cmd);
}

/**
 *main -  Is a super simple shell program
 *Return: An integer 0
 */

int main(void)
{
	char *args[MAX_LINE / 2 + 1];
	char line[MAX_LINE];

	int interactive = isatty(STDIN_FILENO);

	do {
		if (interactive)
		{
			printf("$ ");
			fflush(stdout);
		}

		while (fgets(line, MAX_LINE, stdin) != NULL)
		{
			parse_line(line, args);
			if (args[0] != NULL)
			{
				execute_command(args);
			}

			if (interactive)
			{
				printf("$ ");
				fflush(stdout);
			}
		}
	} while (interactive);

	return (0);
}
