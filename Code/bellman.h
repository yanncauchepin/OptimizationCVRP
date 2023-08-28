#if ! defined (BELLMAN_H)
#define BELLMAN_H 1

#include "split.h"

/*
 * SPECIFICATIONS
 * 
 * L'algorithme de Bellman permet de déterminer des plus courts chemins depuis
 * un sommet source donné dans un graphe orienté pondéré.
 *
 * Cet algorithme prend en entrée :
 *  - G : une structure graphe défini dans split.h
 *
 * Cet algorithme donne en sortie :
 *  - potentiels : vecteur de n réels correspondant aux potentiels des sommets
 *  - pere : vecteur de n entiers correspondant aux pères de chaque sommet utile
 *    l'élaboration du plus court chemin
 *
 */

extern void bellman(struct graphe* G, float *potentiels, int *pere);

#endif
