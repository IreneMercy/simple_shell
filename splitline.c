#include "shell.h"

/**
 * splitline - split line of input given
 * @line: line of input
 * @args: arguments
 * Return: 0
 */

int splitline(char *line, char *args[])
{
	int numArgs = 0;
	char *token = strtok(line, " ");

	while (token != NULL && numArgs < MAX_ARGS - 1)
	{
		args[numArgs++] = token;
		token = strtok(NULL, " ");
	}
	args[numArgs] = NULL;
	return (numArgs);
}
