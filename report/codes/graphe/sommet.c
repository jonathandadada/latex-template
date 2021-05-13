#include <stdlib.h>
#include "sommet.h"

/* met deja tous les sommets a blanc, distance infini et pas de pere */
void initialiser_sommet_largeur(sommet_t* sommet, int id){
	sommet->id = id;
	sommet->couleur = BLANC;
	sommet->distance = INFINI;
	sommet->pere = NULL;
}

void initialiser_sommet_profondeur(sommet_t* sommet, int id){
	sommet->id = id;
	sommet->couleur = BLANC;
	sommet->date_d = 0;
	sommet->date_f = -1;
	sommet->pere = NULL;
}
