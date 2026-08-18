#include "simple_shell.h"

/**
 * get_path - Searches for PATH in the environment
 *
 * Return: Pointer to PATH value, otherwise NULL
 */
char *get_path(void)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (environ[i][0] == 'P' &&
		    environ[i][1] == 'A' &&
		    environ[i][2] == 'T' &&
		    environ[i][3] == 'H' &&
		    environ[i][4] == '=')
		{
			return (environ[i] + 5);
		}
		i++;
	}

	return (NULL);
}

/**
 * find_command - Searches for a command in PATH
 * @command: Command to search for
 *
 * Return: Full path of the command if found, otherwise NULL
 */
char *find_command(char *command)
{
	char *path;
	char *path_copy;
	struct stat st;
	char *result;

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0)
			return (strdup(command));

		return (NULL);
	}

	path = get_path();
	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	result = tokenizator(path_copy, command);
	free(path_copy);

	return (result);
}