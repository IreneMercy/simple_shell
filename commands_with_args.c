#include <string.h>
#include "shell.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

char **split_line(char *line)
{
	char **tokens = malloc(sizeof(char *) * 32);
	int token_count = 0;
	char *token = strtok(line, " ");

	while (token != NULL && token_count < 32)
	{
		tokens[token_count++] = token;
		token = strtok(NULL, " ");
	}
	tokens[token_count] = NULL;
	return (tokens);
}

void execute_line(char *line)
{
	char **tokens = split_line(line);

	if (tokens[0] != NULL)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			execvp(tokens[0], tokens);
			perror("execvp");
			_exit(1);
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			wait(NULL);
		}
	}
	free(tokens);
}
