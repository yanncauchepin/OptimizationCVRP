#include <stdlib.h>
#include "split.h"

void init_graphe(struct graphe* G, int n) {
	G->n = n;
	G->m = 0;
	G->head = (int*)malloc((n-1)*sizeof(int));
	G->succ = (int*)malloc(1*sizeof(int));
	G->cost = (float*)malloc(1*sizeof(float));

	int i;
	for (i=0;i<(n-1);i++) {
		G->head[i] = -1;
	}
}

void ajouter_arc(struct graphe* G, int predecesseur, int successeur, float cout) {
	if (G->m == 0) {
		G->head[0] = G->m;
		G->succ[G->m] = successeur;
		G->cost[G->m] = cout;
		G->m += 1;
	} else {
		// Tableau head
		if (G->head[predecesseur] == -1) {
			G->head[predecesseur] = G->m;
		}

		// Tableau succ
		G->succ = realloc(G->succ, (G->m+1)*sizeof(int));
		G->succ[G->m] = successeur;		

		// Tableau cost
		G->cost = realloc(G->cost, (G->m+1)*sizeof(float));
		G->cost[G->m] = cout;

		G->m += 1;
	}
}

void split(int n, int* T, int Q, float** dist, int* q, struct graphe* H) {
	int i;
	int j;
	int load;
	float cost;

	for (i=0;i<n-1;i++) {
		j = i;
		load = 0;

		while (j < n-1 && load <= Q) {
			load += q[T[j]-1];
			
			if (i == j) {
				cost = dist[0][T[i]] + dist[T[i]][0];
			} else {
				cost = cost - dist[T[j-1]][0] + dist[T[j-1]][T[j]] + dist[T[j]][0];
			}

			if (load <= Q) {
				ajouter_arc(H, i, j+1, cost);
			}

			j += 1;
		}
	}
}

void clear_graphe(struct graphe* G) {
	free(G->head);
	free(G->succ);
	free(G->cost);
}
