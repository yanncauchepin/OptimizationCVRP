#if ! defined (BELLMAN_H)
#define BELLMAN_H 1

#include "split.h"

/* SPECIFICATIONS

Bellman's algorithm determines the shortest paths from a given source vertex
in a weighted directed graph.

This algorithm takes as input :
- graph : a graph structure defined in split.h

This algorithm produces as output :
- potentials : a vector of real numvers corresponding to the potentials of the
vertices.
- parents : a vector of integers corresponding to the parents of each vertex
used in the construction of the shortest path.

 */

extern void bellman (struct graph*, double*, int*) ;

#endif
