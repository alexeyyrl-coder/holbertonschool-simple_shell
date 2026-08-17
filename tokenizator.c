#include "simple_shell.h"

char *tokenizator(char *path_copy, char *command)
{
        char *token;
        struct stat st;
        char *candidate; /* assemble token + "/" + command */

        token = strtok(path_copy, ":");

    while (token != NULL)
    {
        
        candidate = malloc(strlen(token)+strlen(command)+2);
        if (candidate == NULL)
        {
            return(NULL);
        }        

        strcpy(candidate, token);
        strcat(candidate,"/");
        strcat(candidate, command);

        if (stat(candidate, &st) == 0)
        {
            return (candidate);
        }

        free(candidate);
        
        token = strtok(NULL, ":");
    }

    return (NULL);
}