#include "shell.h"
#define BUFFER_SIZE 1024

/*
 *
 * _getline - Reads input from a stream.
 *
 * Return: a pointer to the line of input, or NULL on failure
 */

char *_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos;
	int chars_read = 0;
	char *line = NULL;
	int line_pos = 0;
	int line_size = 0;

	while (1)
	{
		if (buffer_pos >= chars_read)
		{
			buffer_pos = 0;
			chars_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (chars_read <= 0)
				return (NULL);
		}

		while (buffer_pos < chars_read && buffer[buffer_pos] != '\n')
		{
			if (line_pos >= line_size)
			{
				line_size += 64;
				line = realloc(line, line_size);
			}
			line[line_pos++] = buffer[buffer_pos++];
		}

		if (buffer_pos < chars_read && buffer[buffer_pos] == '\n')
		{
			if (line_pos >= line_size)
			{
				line_size += 64;
				line = realloc(line, line_size);
			}
			line[line_pos++] = buffer[buffer_pos++];
			line[line_pos] = '\0';
			return (line);
		}
	}
}
