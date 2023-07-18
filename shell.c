#include "shell.h"

char *findExecutable(char *command);

/**
 * executeCommand - execute command
 * @command: handles forking of the process
 *
 */

void executeCommand(char *command)
{
	char *full_path = findExecutable(command);
	pid_t pid;

	if (full_path != NULL)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("No such file");
			_exit(EXIT_FAILURE);
		}

		else if (pid == 0)
		{
			char *args[2];

			args[0] = (char *)full_path;
			args[1] = NULL;

			execve(full_path, args, NULL);
			perror("No such file");
			_exit(EXIT_FAILURE);
		}

		else
		{
			waitpid(pid, NULL, 0);
		}
	}

	else
	{
		perror("Command not found");
	}
}

char previous_dir[MAX_LEN] = "";
void changeDir(char *path, char *previous_dir);

/**
 * shellLoop - prompts user for input
 * reads command and execute it
 */

void shellLoop(void)
{
	size_t buffer_size = BUFFER_SIZE;
	char *command = NULL;
	ssize_t nbytes;
	char *directory;

	while (1)
	{
		write(STDOUT_FILENO, "(Shell)# ", 9);
		fflush(stdout);
		nbytes = getline(&command, &buffer_size, stdin);

		if (nbytes == -1)
		{
			write(STDERR_FILENO, "\n", 1);
			break;
		}

		if (nbytes > 0 && command[nbytes - 1] == '\n')
		{
			command[nbytes - 1] = '\0';
		}

		if (_strcmp(command, "exit") == 0)
		{
			break;
		}

		else if (_strcmp(command, "cd") == 0)
		{
			if (previous_dir[0] == '\0')
			{
				perror("No previous directory");
			}

			else
			{
				changeDir(previous_dir, previous_dir);
			}
		}

		else if (_strncmp(command, "cd ", 3) == 0)
		{
			directory = command + 3;
			changeDir(directory, previous_dir);
		}

		else
		{
			executeCommand(command);
		}
	}

	free(command);
}

/**
 * shell_main - entry point
 * Return: 0
 */

int shell_main(void)
{
	shellLoop();

	return (0);
}
