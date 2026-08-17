#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
void forkos(char *command, char **args);
int whileprocess(char *program_name);
char *find_command(char *command);
char *tokenizator(char *path_copy, char *command);

#endif