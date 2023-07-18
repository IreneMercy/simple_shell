#include "shell.h"

/**
 * readLine - reads line
 * @inputFile: file for input
 * @line: line of command
 * @maxLen: maximumm length of line
 */

void readLine(int inputFile, char *line, int maxLen)
{
	int read_byte = 0;
	int total_bytes = 0;
	char temp_storage;

	while (total_bytes < maxLen - 1)
	{
		read_byte = read(inputFile, &temp_storage, 1);

		if (read_byte == -1)
		{
			perror("Read error");
			exit(EXIT_FAILURE);
		}

		else if (read_byte == 0 || temp_storage == '\n')
		{
			break;
		}

		else
		{
			line[total_bytes++] = temp_storage;
		}
	}
	line[total_bytes] = '\0';
}
