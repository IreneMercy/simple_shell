#include "shell.h"

/**
 * _copyenv - Creates a copy of the environment.
 *
 * Return: If an error occurs - NULL.
 *   O/w - a double pointer to the new copy.
 */

char **_copyenv(void)
{
	char **new_enviroment;
	size_t size;
	int index;

	for (size = 0; environ[size]; size++)
		;

	new_enviroment = malloc(sizeof(char *) * (size + 1));
	if (!new_enviroment)
		return (NULL);

	for (index = 0; environ[index]; index++)
	{
		new_enviroment[index] = malloc(_strlen(environ[index]) + 1);

		if (!new_enviroment[index])
		{
			for (index--; index >= 0; index--)
				free(new_enviroment[index]);
			free(new_enviroment);
			return (NULL);
		}
		_strcpy(new_enviroment[index], environ[index]);
	}
	new_enviroment[index] = NULL;

	return (new_enviroment);
}

/**
 * free_env - Frees the the environment copy.
 */
void free_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
		free(environ[index]);
	free(environ);
}

/**
 * _getenv - Gets an environmental variable from the PATH.
 * @var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char **_getenv(const char *var)
{
	int index, len;

	len = _strlen(var);
	for (index = 0; environ[index]; index++)
	{
		if (_strncmp(var, environ[index], len) == 0)
			return (&environ[index]);
	}

	return (NULL);
}

/*
 * this is a heleper file
 * for the enviroments files
 */
