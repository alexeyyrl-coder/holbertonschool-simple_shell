#include "simple_shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 *
 * Return: Exit status of the shell
 */
int main(int argc, char **argv)
{
	(void)argc;

	return (whileprocess(argv[0]));
}