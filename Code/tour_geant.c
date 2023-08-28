#include "tour_geant.h"

#define VRAI 1
#define FAUX 0

void tour_geant(int debut, int n, float** M, int* T) {
    int i;
    int j;
    
    // Initialisation pour la recherche des minimums
    int ind_min;
    float min;
    
    // Tableau de booléens des clients déjà visités
    int mark[n];
    for (i=0;i<n;i++) {
        mark[i] = FAUX;
    }
    
    // Client courant
    int courant = debut;

    for (i=0;i<n;i++) {
        // On ajoute le client courant dans le tableau T et on le marque
        T[i] = courant;
        mark[courant-1] = VRAI;
        
        // On initialise les variables pour la recherche du plus proche voisin
        j = 1;
        while ((mark[j-1] == VRAI || M[courant][j] == 0) && (j <= n)) {
            j++;
        }
        
        ind_min = j;
        min = M[courant][ind_min];
        
        // On parcours une colonne à la recherche du plus proche voisin non marqué
        for (j=1;j<n+1;j++) {
            if (mark[j-1] == FAUX && M[courant][j] != 0) {
                if (M[courant][j] < min) {
                    min = M[courant][j];
                    ind_min = j;
                }
            }
        }
        
        // On change de client
        courant = ind_min;
    }
}
