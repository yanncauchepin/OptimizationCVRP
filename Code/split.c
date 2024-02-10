#include <stdlib.h>
#include "split.h"

void init_graph (struct graph* graph, int nb_vertices) {
	graph->nb_vertices = nb_vertices ;
	graph->nb_edges = 0 ;
	graph->head = (int*)malloc((nb_vertices-1)*sizeof(int)) ;
	graph->successor = (int*)malloc(1*sizeof(int)) ;
	graph->edge_weights = (double*)malloc(1*sizeof(double)) ;
	for (int i=0 ; i<(nb_vertices-1) ; i++) {
		graph->head[i] = -1 ;
	}
}

void add_arc_graph (struct graph* graph, int predecessor, int successor, double cost) {
	if (graph->nb_edges == 0) {
		graph->head[0] = graph->nb_edges ;
		graph->successor[graph->nb_edges] = successor ;
		graph->edge_weights[graph->nb_edges] = cost ;
		graph->nb_edges += 1 ;
	} else {
		if (graph->head[predecessor] == -1) {
			graph->head[predecessor] = graph->nb_edges ;
		}
		graph->successor = realloc(graph->successor, (graph->nb_edges+1)*sizeof(int)) ;
		graph->successor[graph->nb_edges] = successor ;
		graph->edge_weights = realloc(graph->edge_weights, (graph->nb_edges+1)*sizeof(double)) ;
		graph->nb_edges[graph->edge_weights] = cost ;
		graph->nb_edges += 1 ;
	}
}

void split_graph (int size, int* T, int capacity_vehicle, double** distance_matrix, int* delivery_demands, struct graph* graph) {
	int j ;
	for (int i=0 ; i<(size-1) ; i++) {
		j = i ;
		int load = 0 ;
		while (j < (size-1) && load <= capacity_vehicle) {
			load += delivery_demands[T[j]-1] ;
			double cost ;
			if (i == j) {
				cost = distance_matrix[0][T[i]] + distance_matrix[T[i]][0] ;
			} else {
				cost = cost - distance_matrix[T[j-1]][0] + distance_matrix[T[j-1]][T[j]] + distance_matrix[T[j]][0] ;
			}
			if (load <= capacity_vehicle) {
				add_arc_graph (graph, i, j+1, cost) ;
			}
			j += 1 ;
		}
	}
}

void clear_graph(struct graph* graph) {
	free(graph->head) ;
	free(graph->successor) ;
	free(graph->edge_weights) ;
}
