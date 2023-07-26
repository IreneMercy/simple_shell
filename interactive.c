#include "shell.h"
/**
 * Interactive - handles interactive mode
 */
void Interactive(void)
{
	int inputFile = STDIN_FILENO;
	char line[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	int numArgs = 0;
	char previous_dir[MAX_LEN] = "";

	while (1)
		write(STDOUT_FILENO, "(Shell)# ", 9);
		fflush(stdout);
		readLine(inputFile, line, sizeof(line));

		if (feof(stdin) || line[0] == '\0')
			break;

		numArgs = splitline(line, args);
		if (numArgs > 0)
			if (_strcmp(args[0], "exit") == 0)
				break;
			else if (_strcmp(args[0], "cd") == 0)

				if (numArgs == 1)
					changeDir(getenv("$HOME"), previous_dir);
				else
						changeDir(args[1], previous_dir);
			else
				execute(args[0], args);
}
