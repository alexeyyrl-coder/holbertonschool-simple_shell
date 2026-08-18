#include "simple_shell.h"

/**
 * tokenizator - Searches for a command inside PATH directories
 * @path_copy: Copy of the PATH environment variable
 * @command: Command to search for
 *
 * Return: Full command path if found, otherwise NULL
 */
char *tokenizator(char *path_copy, char *command)
{
	char *token;
	struct stat st;
	char *candidate;

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		candidate = malloc(strlen(token) + strlen(command) + 2);
		if (candidate == NULL)
			return (NULL);

		strcpy(candidate, token);
		strcat(candidate, "/");
		strcat(candidate, command);

		if (stat(candidate, &st) == 0)
			return (candidate);

		free(candidate);

		token = strtok(NULL, ":");
	}

	return (NULL);
}