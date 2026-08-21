# Simple Shell

## Description

`simple_shell` est un interpréteur de commandes Unix minimal écrit en C dans
le cadre du projet Holberton School. Il lit une commande, la transforme en
arguments, recherche son exécutable et lance le processus correspondant.

Ce projet a été réalisé en binôme avec **Leonid Kuryshev**.

L'objectif principal du projet est de comprendre le fonctionnement interne
d'un shell Unix, notamment la création de processus, l'exécution de programmes,
la recherche de commandes dans `PATH`, la gestion de l'environnement et la
différence entre les modes interactif et non interactif.

---

## Objectifs du projet

À travers ce projet, nous avons travaillé sur plusieurs notions fondamentales
du système Unix :

- Comprendre le fonctionnement d'un shell.
- Comprendre ce qu'est un processus.
- Comprendre les PID et les processus enfants.
- Utiliser `fork` pour créer un processus.
- Utiliser `execve` pour exécuter un programme.
- Utiliser `waitpid` pour attendre un processus enfant.
- Comprendre et utiliser la variable `PATH`.
- Rechercher un exécutable dans les répertoires de `PATH`.
- Manipuler l'environnement du processus.
- Différencier une fonction d'un appel système.
- Gérer les entrées interactives et non interactives.
- Gérer la fin de fichier (`EOF`).
- Implémenter des commandes internes comme `exit`.

---

## Fonctionnalités

Le shell prend actuellement en charge :

- Mode interactif avec affichage du prompt `#cisfun$ `.
- Mode non interactif avec lecture depuis l'entrée standard.
- Découpage des commandes selon les espaces et les tabulations.
- Exécution des commandes avec `fork`, `execve` et `waitpid`.
- Exécution d'un chemin absolu ou relatif contenant `/`.
- Recherche des commandes dans les répertoires de la variable `PATH`.
- Commande interne `exit`.
- Gestion de la fin de fichier (`EOF`).
- Gestion des commandes introuvables.
- Retour du statut de la dernière commande traitée.
- Accès aux variables d'environnement via `environ`.

---

## Compilation

Le projet peut être compilé avec GCC :

```sh
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh