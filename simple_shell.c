#include "simple_shell.h"

/*
*c'est l'exo 2. simpel shell 0.1
*/

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

int main(void)
{
    char *command = NULL;
    size_t taille = 0;
    ssize_t getline_result;
    char *args[64];
    char *token;
    int i;


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
                {
                    command[getline_result - 1] = '\0';
                }
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
                    forkos(command, args);
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