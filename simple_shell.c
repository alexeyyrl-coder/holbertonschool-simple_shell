#include "simple_shell.h"

/*
*c'est l'exo 2. simpel shell 0.1
*/

void forkos(char *command)
{
    pid_t child_pid;

    child_pid = fork();
            if (child_pid < 0)
            {
                perror("error");
            }
            else if (child_pid == 0)
            {
                char *argv[2];

                argv[0] = command;
                argv[1] = NULL;

                execve(command, argv, environ);

                perror(command);
                free(command);
                _exit(127);
            }
            else
            {
                waitpid(child_pid, NULL, 0);
            }
}

int main(void)
{
    char *command = NULL;
    size_t taille = 0;
    ssize_t getline_result;
    


    while (1)
    {
        if(isatty(STDIN_FILENO))
        {
            printf("#cisfun$ ");
            fflush(stdout);
        }

        getline_result = getline(&command, &taille, stdin);

        if(getline_result != -1)
        {
            if (command[getline_result - 1] == '\n')
                command[getline_result - 1] = '\0';
            forkos(command);
        }

        if (getline_result == -1)
        {
            
            if (isatty(STDIN_FILENO))
                printf("\n");

            free(command);
            return (0);
        }
    }

    return (0);
}