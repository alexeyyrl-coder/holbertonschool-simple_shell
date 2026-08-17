start_initialisation()
{
    récupérer environnement
    initialiser les variables nécessaires

    boucle_programme()
}


boucle_programme()
{
    tant que le shell fonctionne
    {
        si mode interactif
            afficher prompt

        attendre une ligne

        si EOF
            quitter proprement

        transformer la ligne en commande + arguments

        si ligne vide
            recommencer

        si commande == exit
            quitter proprement

        si commande == env
            afficher environnement

        chercher_commande()

        si commande introuvable
            afficher erreur
        sinon
            command_execute()

        libérer la mémoire temporaire
    }
}


chercher_commande()
{
    si chemin direct
        vérifier s'il existe

    sinon
        chercher dans PATH

    retourner chemin trouvé
    ou échec
}


command_execute()
{
    fork

    enfant:
        execve

    parent:
        wait
}


quitter_shell()
{
    libérer les allocations appartenant au shell
    terminer le processus principal
}