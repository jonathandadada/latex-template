#include <stdlib.h>
#include <stdio.h>
#include "cellule.h"
#include "liste.h"

/* retourne 0 si erreur */
int initialiser_liste(liste_t* l){
	int invariant = 1;
	if(l != NULL){
		l->tete = NULL;
	} else {
		invariant = 0;
	}
	return invariant;
}

void inserer(liste_t* l, cellule_t* x){
	x->succ = l->tete;
	if(l->tete != NULL){
		l->tete->pred = x;
	}
	l->tete = x;
	x->pred = NULL;
}

/* liste_t* creer_liste(int* tab, int nb_elements){
	liste_t* l = (liste_t*)malloc(sizeof(liste_t));
	for(int i = nb_elements - 1; i >= 0; --i){
		inserer_liste(l,creer_cellule(tab[i]));
	}
	return l;
} */

void detruire_liste(liste_t* l){
	if(l != NULL && l->tete != NULL){
		cellule_t* c;
		while(l->tete != NULL){
			c = l->tete;
			l->tete = l->tete->succ;
			detruire_cellule(&c);
		}
	} else {
		printf("La liste est vide et non allouee");
	}
}

void supprimer(liste_t* l, cellule_t* x){
	if(x->pred != NULL){
		x->pred->succ = x->succ;
	} else {
		l->tete = x->succ;
		if(l->tete != NULL){
			l->tete->pred = NULL;
		}
	}
}

cellule_t* rechercher(liste_t* l, int k){
	cellule_t* x = l->tete;
	while(x != NULL && x->cle != k){
		x = x->succ;
	}
	return x;
}

void afficher_liste(liste_t* l){
	if(l != NULL){
		cellule_t* x = l->tete;
		while(x != NULL){
			printf("%d ", x->cle);
			x = x->succ;
		}
		printf("\n");
	}
}
