#include "simple_shell.h"

int whileprocess(void)
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
}