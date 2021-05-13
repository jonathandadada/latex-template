#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "graphe.h"

#define		SOMMETDEPART		0

int main(int argc, char* argv[]){
	if(argc != 2){
		exit(EXIT_FAILURE);
	}
	
	int i;
	graphe_t graphe;
	sommet_t* sommets;
	initialiser_graphe(&graphe,argv[1]);
	sommets = (sommet_t*)malloc(sizeof(sommet_t)*graphe.n_sommets);
	printf("##### affichage du graphe ##### \n");
	afficher_graphe(&graphe);
	printf("##### fin d'affichage du graphe ##### \n");
	
	printf("\n##### parcours en largeur via m_adj ##### \n");
	parcours_largeur_matrice(&graphe,sommets,&sommets[SOMMETDEPART]);
	printf("##### affichage des plus courts chemins de 0 a tout autre sommet##### \n");
	for(i = 0; i < graphe.n_sommets; ++i){ 
		afficher_chemin(&graphe,&sommets[SOMMETDEPART],&sommets[i]);
		printf("\n");
	}
	printf("##### fin traitement via m_adj ##### \n");
	
	printf("\n##### parcours en largeur via l_adj ##### \n");
	parcours_largeur_liste(&graphe,sommets,&sommets[SOMMETDEPART]);
	printf("##### affichage des plus courts chemins de 0 a tout autre sommet#####\n");
	for(i = 0; i < graphe.n_sommets; ++i){ 
		afficher_chemin(&graphe,&sommets[SOMMETDEPART],&sommets[i]);
		printf("\n");
	}
	printf("##### fin traitement via l_adj##### \n");
	printf("Les resultats sont coherents (algorithme deroulee a la main sur graphe2.txt pour le parcours en largeur)\n");
	
	printf("\n##### parcours en profondeur via m_adj #####\n");
	parcours_profondeur_matrice(&graphe,sommets);
	afficher_parcours_profondeur(&graphe,sommets);
	printf("resultat coherent (algorithme deroulee a la main sur graphe4.txt pour parcours en profondeur)\n");
	
	printf("\n##### parcours en profondeur iteratif #####\n");
	parcours_profondeur_iteratif(&graphe,sommets);
	afficher_parcours_profondeur(&graphe,sommets);
	printf("Les dates de fins sont eronnees pour le parcours en profondeur iteratif, les peres sont bons, certains sommets ne passent pas a noir\n");
	
	detruire_graphe(&graphe);
	free(sommets);

	return EXIT_SUCCESS;
}
