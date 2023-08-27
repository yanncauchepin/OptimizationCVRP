#if ! defined (TOUR_GEANT_H)
#define TOUR_GEANT_H 1

/*
 * SPECIFICATIONS
 * 
 * Un Tour géant représente une tournée de véhicule où est utilisé un unique
 * véhicule n'ayant aucune limitation de chargement. Ici, le but est de trouver
 * un ordre initial de livraison des clients, appelé Tour géant.
 * 
 * Cet algorithme prend en entrée :
 *  - n : entier supérieur ou égal à 1 correspondant au nombre de clients
 *  - début : entier compris entre 1 et n inclus correspond au premier client
 *  - M : matrice d'adjacence dont les valeurs non nulles sont les distances
 *
 * Cet algorithme donne en sortie :
 *  - T : vecteur d'entiers dans lequel la solution trouvée est stockée
 *
 */

extern void tour_geant(int debut, int n, float** M, int* T);

#endif
