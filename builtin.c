#include "shell.h"
/**
 * get_builtin - Matches a command with a corresponding
 *               shellby builtin function.
 * @command: The command to match.
 *
 * Return: A function pointer to the corresponding builtin.
 */
int (*get_builtin(char *command))(char **args, char **front)
{
	builtin_t funcs[] = {
		{ "exit", shell_exit },
		{ "env", _env },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; funcs[i].name; i++)
	{
		if (_strcmp(funcs[i].name, command) == 0)
			break;
	}
	return (funcs[i].f);
}
/**
 * shell_exit - Causes normal process termination
 *                for the shell.
 * @args: An array of arguments containing the exit value.
 * @front: A double pointer to the beginning of args.
 *
 *  Return: If there are no arguments - -3.
 *         If the given exit value is invalid - 2.
 *         O/w - exits with the given status value.
 */

int shell_exit(char **args, char **front)
{
	int status = 0;
	alias_t *aliases = NULL;
	int max = 1 << (sizeof(int) * 8 - 1);

	if (args[1])
	{
		status = atoi(args[1]);
	}
	else
	{
		return (-3);
	}

	if (status > max - 1)
	{
		perror("could not quit");
		return (-1);
	}

	free_args(args, front);
	free_env();
	free_alias_list(aliases);
	exit(status);
}

/**
 *free_alias_list - frees the meory for alias
 *
 *@head: takes the parameters to be passed
 */
void free_alias_list(alias_t *head)
{
	alias_t *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}
