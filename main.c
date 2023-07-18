#include "shell.h"

/**
 * main - executes main functions
 * Return: 0
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		Interactive();
	}
	else
	{
		nonInteractive();
	}
	return (0);
}
