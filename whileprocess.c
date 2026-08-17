#include "simple_shell.h"

int whileprocess(void)
{
    char *command = NULL; /*pointe vers la la commende*/
    size_t taille = 0; /*initialiste la taille de la commende */
    ssize_t getline_result; /* nombre de caractères lus par getline */
    char *args[64]; /*prend la commende*/
    char *token; /*decoupe la commende*/
    int i; /*variable conter*/
    char *resolved;


    while (1) /*boucle programme*/
    {
        if(isatty(STDIN_FILENO)) /*si le terminal prend l'entréer du clavier (isatty = terminal)(STDIN_FILEON = entrer du clavier) ça permet au shell de distinguer le mod interactifs*/
        {
            printf("#cisfun$ "); /*affiche le prompte du shell*/
            fflush(stdout); /*stdout c'est l'output standar (stdou = claveir) (fflush = ramplace le /n pour forcer l'afficheage)*/
        }

        getline_result = getline(&command, &taille, stdin); /*visiblement ça prend la commend commende ça taille et encore le stdin je sais pas*/

        if(getline_result != -1) /*determine si le getline_resulte n'est pas vide*/
        {

            if (command[getline_result - 1] == '\n') /*detecte le à la ligne*/
                {
                    command[getline_result - 1] = '\0'; /* supprime le a la ligne*/
                }
                i = 0; /* mette le compter à zero*/
                token = strtok(command, " \t"); /*token contient la version découper de commende*/

                while (token != NULL && i < 63) /* c'verifie si token existe et si il est inférieur a i car on a 63 case max */
                {
                args[i] = token;
                i++;
                token = strtok(NULL, " \t"); /*decoupe le token et vire les nulle, je sais pas se que fait le \t */
                }

                args[i] = NULL; /* ajoute une marque de fin pour que le forkos puissent les utiliser*/
                if (args[0] != NULL)
                {
                    resolved = find_command(args[0]);

                    if (resolved != NULL)
                    {
                        args[0] = resolved;
                        forkos(command, args);
                        free(resolved);
                    }
                }

            if (getline_result == -1) /* EOF ou erreur de lecture */
            {
            
                if (isatty(STDIN_FILENO))
                    printf("\n");

                free(command); /*libérent la mémoire*/
                return (0);
            }
        }
    }
}