#include "simple_shell.h"

/**
 * process_args - Resolves and executes a command
 * @args: Array of command arguments
 * @command: Command buffer
 * @program_name: Name of the shell program
 * @command_count: Current command number
 *
 * Return: 0 if command is found, otherwise 127
 */
static int process_args(char **args, char *command,
	char *program_name, int command_count)
{
	char *resolved;

	if (args[0] == NULL)
		return (0);

	if (strcmp (args[0], "exit") == 0)
    {
        free (command);
        exit (0);
    }

	resolved = find_command(args[0]);

	if (resolved != NULL)
	{
		args[0] = resolved;
		forkos(command, args);
		free(resolved);
		return (0);
	}

	fprintf(stderr, "%s: %d: %s: not found\n",
		program_name, command_count, args[0]);

	return (127);
}

/**
 * whileprocess - Reads and executes commands entered by the user
 * @program_name: Name of the shell program
 *
 * Return: Last command status
 */
int whileprocess(char *program_name)
{
	char *command = NULL;
	size_t taille = 0;
	ssize_t getline_result;
	char *args[64];
	char *token;
	int i;
	int status = 0;
	int command_count = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}

		getline_result = getline(&command, &taille, stdin);

		if (getline_result != -1)
		{
			if (command[getline_result - 1] == '\n')
				command[getline_result - 1] = '\0';

			i = 0;
			token = strtok(command, " \t");

			while (token != NULL && i < 63)
			{
				args[i] = token;
				i++;
				token = strtok(NULL, " \t");
			}

			args[i] = NULL;

			if (args[0] != NULL)
			{
				command_count++;
				status = process_args(args, command,
					program_name, command_count);
			}
		}

		if (getline_result == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");

			free(command);
			return (status);
		}
	}
}