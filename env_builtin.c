#include "shell.h"

int env(char **args, char __attribute__((__unused__)) **front);
int _setenv(char **args, char __attribute__((__unused__)) **front);
int _unsetenv(char **args, char __attribute__((__unused__)) **front);

/**
 * _env - Prints the current environment.
 *
 * @args: picks the arguments past to it
 * @front: picks the current argument
 *
 * Return: Always returns 0.
 */

int _env(char **args, char __attribute__((__unused__)) **front)
{
	int index;
	char nc = '\n';

	if (!environ)
		return (-1);

	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, &nc, 1);
	}

	(void)args;
	return (0);
}

/**
 * _setenv - Changes or adds an environmental variable to the PATH.
 *
 * @args: The command arguments.
 * @front: The front of the argument list
 *
 *Return: 0 on success, -1 on failure.
 */

int _setenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_variable = NULL, **new_enviroment, *new_value;
	size_t size;
	int index;

	if (!args[0] || !args[1])
		perror("number of args");

	new_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_value)
		perror("many args");
	_strcpy(new_value, args[0]);
	_strcat(new_value, "=");
	_strcat(new_value, args[1]);

	env_variable = _getenv(args[0]);
	if (env_variable)
	{
		free(*env_variable);
		*env_variable = new_value;
		return (0);
	}
	for (size = 0; environ[size]; size++)
		;

	new_enviroment = malloc(sizeof(char *) * (size + 2));
	if (!new_enviroment)
	{
		free(new_value);
		perror("error");
	}

	for (index = 0; environ[index]; index++)
		new_enviroment[index] = environ[index];

	free(environ);
	environ = new_enviroment;
	environ[index] = new_value;
	environ[index + 1] = NULL;

	return (0);
}

/**
 * _unsetenv - Removes an environmental variable from the PATH.
 *
 * @args: picks the arguments past to it
 * @front: picks the current argument
 *
 * Return: Always returns 0.
 */

int _unsetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_variable, **new_enviroment;
	size_t size;
	int index, index1;

	if (!args[0])
		perror("error");
	env_variable = _getenv(args[0]);
	if (!env_variable)
		return (0);

	for (size = 0; environ[size]; size++)
		;

	new_enviroment = malloc(sizeof(char *) * size);
	if (!new_enviroment)
		perror("erro");

	for (index = 0, index1 = 0; environ[index]; index++)
	{
		if (*env_variable == environ[index])
		{
			free(*env_variable);
			continue;
		}
		new_enviroment[index1] = environ[index];
		index1++;
	}
	free(environ);
	environ = new_enviroment;
	environ[size - 1] = NULL;

	return (0);
}

