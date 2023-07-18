#include "shell.h"

/**
 * findExecutable - find exucutable to a given command within path
 * @command: command inputed
 * Return: 0
 */

char *findExecutable(char *command)
{
	char *path = getenv("PATH");
	char *dir;
	char *copy_of_path;
	char buffer[MAX_LEN];
	int path_exist;

	if (command == NULL || command[0] == '\0')
	{
		return (NULL);
	}

	if (_strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
		{
			return (strdup_custom(command));
		}

		else
		{
			return (NULL);
		}
	}

	if (_strcmp(command, "exit") == 0)
	{
		exit(0);
	}

	if (path == NULL)
	{
		perror("Path not found");
		return (NULL);
	}

	copy_of_path = malloc(_strlen(path) + 1);
	if (copy_of_path == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	_strcpy(copy_of_path, path);

	path_exist = 0;
	dir = strtok(copy_of_path, PATH_DELIMITER);
	while (dir != NULL)
	{
		_strcpy(buffer, dir);
		_strcat(buffer, "/");
		_strcat(buffer, command);

		if (access(buffer, F_OK) == 0)
		{
			path_exist = 1;
			break;
		}
		dir = strtok(NULL, PATH_DELIMITER);
	}
	free(copy_of_path);

	if (!path_exist)
	{
		perror("Command not found");
		return (NULL);
	}

	return (strdup_custom(buffer));
}
