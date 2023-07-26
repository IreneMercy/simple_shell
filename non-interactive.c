#include "shell.h"


/**
 * nonInteractive - handles non interactive mode
 * Return: 0
 */

void nonInteractive(void)
{
	char line[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	int progress = -1;
	int numArgs, i;

	while (progress == -1)
	{
		readLine(STDIN_FILENO, line, sizeof(line));
		numArgs = splitline(line, args);
		execute(args[0], args);

		for (i = 0; i < numArgs; i++)
		{
			free(args[i]);
		}
	}
}
