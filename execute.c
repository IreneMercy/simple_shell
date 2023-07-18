#include "shell.h"

/**
 * execute - executes commands
 * @command: command inputed
 * @args: arguments given
 */

void execute(char *command, char *args[])
{
	char *path = getenv("PATH");
	char *dir;
	char fullPath[100];
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	else if (pid == 0)
	{
		if (command[0] == '/')
		{
			execve(command, args, NULL);
		}

		else
		{
			while ((dir = strtok(path, ":")) != NULL)
			{
				_strcpy(fullPath, dir);
				_strcat(fullPath, "/");
				_strcat(fullPath, command);
				execve(fullPath, args, NULL);
				path = NULL;
			}
		}

		perror("Command not found");
		exit(EXIT_FAILURE);
	}

	else
	{
		waitpid(pid, NULL, 0);
	}
}

