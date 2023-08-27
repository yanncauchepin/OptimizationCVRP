#include <stdio.h>
#include <stdlib.h>
#include "bellman.h"
#include "split.h"
#include "tour_geant.h"

int main(int argc, char *argv[]) {
    /*
     * Import des données depuis le fichier source
     */
    
    int i;
    int j;

    // Ouverture du fichier source
    FILE *fic;
    fic = fopen(argv[1], "r");

    // Nombre de clients à livrer
    int n;
    fscanf(fic, "%d\n", &n);
    
    // Capacité maximale des véhicules
    int Q;
    fscanf(fic, "%d\n", &Q);
    
    // Demandes de livraison
    int *q;
    q = (int *)malloc((n+1)*sizeof(int));
    for (i=0;i<n;i++) {
        fscanf(fic, "%d", &q[i]);
    }
    
    // Distances
    float **M;
    M = (float **)malloc((n+1)*sizeof(float*));
    for (i=0;i<n+1;i++) {
        M[i] = (float *)malloc((n+1)*sizeof(float));
        for (j=0;j<n+1;j++) {
            fscanf(fic, "%f", &M[i][j]);
        }
    }

    // Fermeture du fichier source
    fclose(fic);

    /*
     * Création d'un tour géant
     */

    int *T;
    T = (int*)malloc(n*sizeof(int));

    tour_geant(atoi(argv[2]), n, M, T);

    /*
     * Construction d'un graphe auxiliaire avec la procédure SPLIT
     */
    
    struct graphe H;
    init_graphe(&H, n+1);

    split(n+1, T, Q, M, q, &H);

    /*
     * Application de l'algorithme de Bellman
     */
    
    float *potentiels;
    int *pere;
    potentiels = (float *)malloc((n+1)*sizeof(float));
    pere = (int *)malloc((n+1)*sizeof(int));
    
    bellman(&H, potentiels, pere);
        
    // Destruction du graphe auxiliaire
    clear_graphe(&H);

    /*
     * Affichage du résultat final
     */
    
    // Résultat : coût
    printf("Coût : %f\n", potentiels[n]);

    // Résultat : tournées
    i=n;
    while (i!=0) {
    	printf("Tournée : ");
        for (j=pere[i];j<i;j++) {
        	printf("%d ", T[j]);
        }
        printf("\n");
        i = pere[i];
    }

    free(q);
    
    for (i=0;i<n+1;i++) {
        free(M[i]);
    }
    free(M);

    free(T);
    free(potentiels);
    free(pere);

    return 0;
}
