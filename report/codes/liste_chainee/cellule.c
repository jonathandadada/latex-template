#include <stdlib.h> /* pour NULL */
#include "cellule.h"

void creer_cellule(cellule_t* c, int val){
    c->succ = NULL;
    c->pred = NULL;
    c->cle = val;
}

void detruire_cellule(cellule_t** c){
	free(*c);
	*c = NULL;
}
