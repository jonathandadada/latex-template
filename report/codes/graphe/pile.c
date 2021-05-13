#include <stdlib.h>
#include <stdio.h>

#include "pile.h"

int pile_vide(pile_t* pile){
	return pile->sommet == -1;
}

int pile_pleine(pile_t* pile){
	return (pile->sommet == (pile->taille - 1));  
}

void initialiser_pile(pile_t* pile, int taille){
	pile->sommet = -1;
	pile->taille = taille;
	pile->sommets = (sommet_t**)malloc(sizeof(sommet_t*)*taille);
}

void empiler(pile_t* pile, sommet_t* sommet){
	if(!pile_pleine(pile)){
		pile->sommet = pile->sommet + 1;
		pile->sommets[pile->sommet] = sommet;
	} else {
		printf("pile : erreur, debordement positif\n");
	}
}

sommet_t* depiler(pile_t* pile){
	sommet_t* tmp = NULL;
	if(!pile_vide(pile)){
		tmp = pile->sommets[pile->sommet];
		pile->sommet = pile->sommet - 1;
	} else {
		printf("pile : erreur, debodement negatif\n");
	}
	return tmp;
}

void detruire_pile(pile_t* pile){
	free(pile->sommets);
}

/* TODO : Supprimer car ne respecte pas la structure d'une pile */
void afficher_pile(pile_t* pile){
	int i = 0;
	while(i <= pile->sommet){
		printf("[%d]\n", pile->sommets[i]->id);
		++i;
	}
} 
