#include "shell.h"

void changeDir(char *path, char *previous_dir)
{
	char current_dir[MAX_LEN]; const char *home; char *new_pwd;

	if (path == NULL || _strcmp(path, "") == 0)
	{
		home = getenv("HOME");
		if (home == NULL)
		{
			perror("Home directory not available");
			return;
		}

		if (chdir(home) != 0)
		{
			perror("Failed to change directory");
		}
	}
	else if (_strcmp(path, "-") == 0)
	{
		if (previous_dir[0] == '\0')
		{
			perror("No previous directory");
			return;
		}

		if (chdir(previous_dir) != 0)
		{
			perror("Failed to change directory");
		}
	}

	else
	{

		if (getcwd(current_dir, sizeof(current_dir)) == NULL)
		{
			perror("Access for current directory denied");
			return;
		}

		if (chdir(path) != 0)
		{
			perror("Access to child directory denied");
			return;
		}

		strncpy_custom(previous_dir, current_dir, sizeof(current_dir) - 1);
		previous_dir[sizeof(current_dir) - 1] = '\0';
	}

	new_pwd = getcwd(current_dir, sizeof(current_dir));

	if (new_pwd != NULL)
	{
		setenv("PWD", new_pwd, 1);
	}

	else
	{
		perror("Failed to get current directory");
	}
}
