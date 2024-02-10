#include <stdio.h>
#include <stdlib.h>
#include "bellman.h"
#include "split.h"
#include "giant_tour.h"


int main (int argc, char *argv[]) {

    if (argc < 2) {
       // Not enough arguments provided, display a message and exit
       printf("Usage : %s <input_file>\n", argv[0]);
       return 1;
    }

    FILE *file = fopen(argv[1], "r") ;

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1 ;
    }

    // IMPORTING DATA FORM THE SOURCE FILE

    file = fopen(argv[1], "r");

    // Get the number of customer to deliver
    int nb_customer;
    fscanf(file, "%d\n", &nb_customer);

    // Get the maximum vehicle capacity
    int capacity_vehicle;
    fscanf(file, "%d\n", &capacity_vehicle);

    // Get the delivery demands
    int *delivery_demands;
    delivery_demands = (int *)malloc((nb_customer+1)*sizeof(int));
    for (int i=0 ; i<nb_customer ; i++) {
        fscanf(file, "%d", &delivery_demands[i]);
    }

    // Get the distance matrix
    double **distance_matrix;
    distance_matrix = (double**)malloc((nb_customer+1)*sizeof(double*));
    for (int i=0 ; i<(nb_customer+1) ; i++) {
        distance_matrix[i] = (double*)malloc((nb_customer+1)*sizeof(double));
        for (int j=0 ; j<(nb_customer+1) ; j++) {
            fscanf(file, "%lf", &distance_matrix[i][j]);
        }
    }

    // Closing the source file
    fclose(file);

    // COMPUTING ALGORITHMS

    // Creating a Giant Tour
    int* T = (int*)malloc(nb_customer*sizeof(int));
    giant_tour(0, nb_customer, distance_matrix, T); //atoi(argv[2])

    // Building an auxiliary graph using the Split procedure
    struct graph graph;
    init_graph(&graph, nb_customer+1);

    split_to_graph(nb_customer+1, T, capacity_vehicle, distance_matrix, delivery_demands, &graph);

    // Application of the Bellman algotihm
    double* potentials = (double*)malloc((nb_customer+1)*sizeof(double));
    int* parents = (int*)malloc((nb_customer+1)*sizeof(int));
    bellman(&graph, potentials, parents);

    // Destruction of the auxiliary graph
    clear_graph(&graph);

    // DISPLAYING THE FINAL RESULT

    // Résultat : coût
    printf("Coût : %f\n", potentials[nb_customer]);

    // Résultat : tournées
    int i = nb_customer;
    while (i!=0) {
    	printf("Tournée : ");
        for (int j=parents[i] ; j<i ; j++) {
        	printf("%d ", T[j]);
        }
        printf("\n");
        i = parents[i];
    }

    // FREE DYNAMICALLY ALLOCATED VARIABLES

    for (int i=0 ; i<(nb_customer+1) ; i++) {
        free(distance_matrix[i]);
    }
    free(delivery_demands);
    free(distance_matrix);
    free(T);
    free(potentials);
    free(parents);
    
    return 0;
}
