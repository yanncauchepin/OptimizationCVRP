#ifndef SPLIT_H
#define SPLIT_H 1

/* SPECIFICATIONS

The splitting procedure allows determining an auxiliary graph, in which the edges
represent the routes and the vertices represent transitions between two routes.

The algorithm requires a graph data structure where :
- nb_vertices : positive integer corresponding to the number of vertices.
- nb_edges : integer corresponding to the number of arcs.
- head : dynamic array of size (nb_vertices-1)
- successor : dynamic array of size nb_edges corresponding to successors.
- edge_weights : dynamic array of size nb_edges corresponding to costs.

 Here, the graph must be sorted in topological order and must not contain cycles.

*/

struct graph {
    int nb_vertices ;    //n
    int nb_edges ;          //m
    int* head ;
    int* successor ;
    double* edge_weights ;    // cost
};

extern void init_graph(struct graph*, int) ;

extern void add_arc_graph(struct graph*, int, int, double) ;

extern void split_to_graph(int, int*, int, double**, int*, struct graph*) ;

extern void clear_graph(struct graph*) ;

#endif
