#include "simple_shell.h"

/**
 * print_environment - Print the current environment
 *
 * Return: Always 0
 */
int print_environment(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}

	return (0);
}