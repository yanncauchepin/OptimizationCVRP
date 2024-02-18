#include "bellman.h"

void bellman (struct graph* graph, double* potentials, int* parents) {

	potentials[0] = 0 ;
	parents[0] = 0 ;

	for (int i=1 ; i<graph->nb_vertices ; i++) {
		potentials[i] = -1 ;
		parents[i] = 0 ;
	}

	for (int i=graph->head[0] ; i<graph->head[1] ; i++) {
		potentials[graph->successor[i]] = graph->edge_weights[i] ;
	}


	for (int i=0; i<graph->nb_vertices-1 ; i++) {
		for (int j=graph->head[i] ; j<graph->head[i+1] ; j++) {
			int value = graph->successor[j] ;
			if ((potentials[i] + graph->edge_weights[j]) < potentials[value] ||
			potentials[value] == -1) {
				potentials[value] = potentials[i] + graph->edge_weights[j] ;
				parents[value] = i ;
			}
		}
	}

	if ((potentials[graph->nb_vertices-2] + graph->edge_weights[graph->nb_edges-1]) < potentials[graph->nb_vertices-1] ||
	potentials[graph->nb_vertices-1] == -1) {
		potentials[graph->nb_vertices-1] = potentials[graph->nb_vertices-2] + graph->edge_weights[graph->nb_edges-1] ;
		parents[graph->nb_vertices-1] = graph->nb_vertices-2 ;
	}

}
