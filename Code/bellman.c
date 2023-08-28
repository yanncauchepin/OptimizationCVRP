#include "bellman.h"

void bellman(struct graphe* G, float* potentiels, int* pere) {
	int i;
	int j;
	int x;
	int y;

	// Initialisation des vecteurs potentiels et pere
	potentiels[0] = 0;
	pere[0] = 0;

	for (i=1;i<G->n;i++) {
		potentiels[i] = -1;
		pere[i] = 0;
	}

	// Pour tout x successeur de la racine
	for (i=G->head[0];i<G->head[1];i++) {
		x = G->succ[i];
		potentiels[x] = G->cost[i];
	}

	// Pour tout y successeur des autres sommets
	for (x=1;x<G->n-1;x++) {
		for (j=G->head[x];j<G->head[x+1];j++) {
			y = G->succ[j];
			if (potentiels[x] + G->cost[j] < potentiels[y] || potentiels[y] == -1) {
				potentiels[y] = potentiels[x] + G->cost[j];
				pere[y] = x;
			}
		}
	}

	// Le dernier sommet n'a pas de successeurs
	if (potentiels[G->n-2] + G->cost[G->m-1] < potentiels[G->n-1] || potentiels[G->n-1] == -1) {
		potentiels[G->n-1] = potentiels[G->n-2] + G->cost[G->m-1];
		pere[G->n-1] = G->n-2;
	}
}
