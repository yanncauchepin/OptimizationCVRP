#if ! defined (GIANT_TOUR_H)
#define GIANT_TOUR_H 1

extern void giant_tour (int, int, double**, int*) ;
/* SPECIFICATIONS

A Giant Tour is a vehicle tour where a single vehicle is used with no load limits.
Here, the aim is to find an initial customer delivery order, called a Giant Tour.

This algorithm takes as input :
nb_customer : integer greater than or equal to 1, corresponding to the number of customers.
start : integer between 1 and nb_customer inclusive, corresponding to the first customer.
distance_matrix : adjacency matrix whose non-zero values are the distances.

The output of this algorithm is :
T : vector of integers in which the solution found is stored

*/

#endif
