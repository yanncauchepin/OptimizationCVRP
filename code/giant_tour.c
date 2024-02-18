#include "giant_tour.h"

#define TRUE 1
#define FALSE 0

void giant_tour (int start, int nb_customer, double** distance_matrix, int* T) {

    // Initialization for finding the minimums
    int index_min ;
    double min ;

    // Array of booleans indicating whether customers have been visited
    int visited [nb_customer] ;
    for (int i=0 ; i<nb_customer ; i++) {
        visited[i] = FALSE ;
    }

    // Current customer
    int current = start ;

    for (int i=0 ; i<nb_customer ; i++) {

        // Add the current customer to the T array and mark it
        T[i] = current ;
        visited[current-1] = TRUE ;

        // Initialize variables for finding the nearest neighbor
        int j = 1 ;
        while ((visited[j-1] == TRUE || distance_matrix[current][j] == 0) && (j <= nb_customer)) {
            j++ ;
        }

        index_min = j ;
        min = distance_matrix[current][index_min] ;

        // Navigate into a column to find the nearest unvisited neighbor
        for (int j=1 ; j<(nb_customer+1) ; j++) {
            if (visited[j-1] == FALSE && distance_matrix[current][j] != 0) {
                if (distance_matrix[current][j] < min) {
                    min = distance_matrix[current][j] ;
                    index_min = j ;
                }
            }
        }

        // Change customer
        current = index_min;
    }
}
