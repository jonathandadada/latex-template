#include <stdlib.h>
#include <stdio.h>

#include "cellule.h"
#include "liste.h"
#include "graphe.h"

int main(int argc, char* argv[])
{
	if(argc != 2) { exit(EXIT_FAILURE); }
	graphe_t* graphe = (graphe_t*)malloc(sizeof(graphe_t));
	initialiser_graphe(graphe,argv[1]);
	afficher_graphe(graphe);
	detruire_graphe(graphe);
	return EXIT_SUCCESS;
}
