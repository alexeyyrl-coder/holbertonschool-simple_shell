#include "simple_shell.h"


char *find_command(char *command)
{
    char *path;
    char *path_copy;
    struct stat st;
    char *result;
    int i;

    if (strchr(command, '/') != NULL)
    {

        if (stat(command, &st) == 0)
        {
            return (strdup(command));
        }
            return(NULL);
    }

    /* 2. récupérer PATH */
    path = NULL;
    i = 0;

    while (environ[i] != NULL)
    {
        if (environ[i][0] == 'P' &&
            environ[i][1] == 'A' &&
            environ[i][2] == 'T' &&
            environ[i][3] == 'H' &&
            environ[i][4] == '=')
        {
            path = environ[i] + 5;
            break;
        }

        i++;
    }

    if (path == NULL)
    {
        return (NULL);
    }

    path_copy = strdup(path);
    if (path_copy == NULL)
    {
        return(NULL);
    }

    result = tokenizator(path_copy, command);

    free(path_copy);
    return (result);
}