#ifndef __PILE_H__
#define __PILE_H__

#include "sommet.h"

typedef struct pile {
	int sommet;
	int taille;
	sommet_t** sommets;
} pile_t;

int pile_vide(pile_t* pile);
int pile_pleine(pile_t* pile);
void initialiser_pile(pile_t* pile, int taille);
void empiler(pile_t* pile, sommet_t* sommet);
sommet_t* depiler(pile_t* pile);
void detruire_pile(pile_t* pile);

void afficher_pile(pile_t* pile);

#endif
