#include "simple_shell.h"


char *find_command(char *command)
{
    char *path;
    char *path_copy;
    struct stat st;
    char *result;

    if (strchr(command, '/') != NULL)
    {

        if (stat(command, &st) == 0)
        {
            return(command)
        }
            return(NULL)
    }

    /* 2. récupérer PATH */
    path = getenv("PATH");
    if (path == NULL)
    {
        return(NULL);
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