#if ! defined (SPLIT_H)
#define SPLIT_H 1

/*
 * SPECIFICATIONS
 * 
 * La procédure de découpage permet de déterminer un graphe auxiliaire, dans
 * lequel les arêtes représentent les tournées et les sommets représentent les
 * transitions entre deux tournées.
 *
 * L'algorithme nécessite avant tout une structure de donnée graphe :
 *  - n : entier strictement positif correspondant au nombre de sommets
 *  - m : entier correspondant au nombre d'arcs
 *  - head : vecteur dynamique de taille n-1
 *  - succ : vecteur dynamique de taille m correspondant aux successeurs
 *  - cost : vecteur dynamique de taille m correspondant aux coûts
 *
 * Ici, le graphe doit être trié dans l'ordre topologique et ne doit pas
 * comporter de cycles.
 *
 * Les actions init_graphe et clear_graphe permettent respectivement
 * d'initialiser et de détruire des graphes.
 *
 * L'action ajouter_arc permet d'ajouter un arc entre deux sommets i et j :
 *  - i : entier correspondant au sommet de départ
 *  - j : entier correspondant au sommet d'arrivée
 *  - cout : réel correspondant à la pondération de l'arc
 */

struct graphe {
	int n;			// Nombre de sommets
	int m;			// Nombre d'arêtes
	int* head;
	int* succ;
	float* cost;	// Pondérations des arêtes
};

extern void init_graphe(struct graphe*, int n);

extern void ajouter_arc(struct graphe*, int i, int j, float cout);

extern void split(int n, int* T, int Q, float** dist, int* q, struct graphe* H);

extern void clear_graphe(struct graphe*);

#endif
