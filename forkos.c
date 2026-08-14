#include "simple_shell.h"

void forkos(char *command, char **args)
{
    pid_t child_pid;

    child_pid = fork();
            if (child_pid < 0)
            {
                perror("error");
            }
            else if (child_pid == 0)
            {

                execve(args[0], args, environ);

                perror(args[0]);
                free(command);
                _exit(127);
            }
            else
            {
                waitpid(child_pid, NULL, 0);
            }
}