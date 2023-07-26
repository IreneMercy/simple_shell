#include <string.h>
#include "shell.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * split_line - splits the commands.
 *
 * @line: takes the argument passed
 */
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

/*
 * execute_line - executes the commands of split line
 *
 * @line: takes the argument passed
 */
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
