#ifndef __SOMMET_H__
#define __SOMMET_H__

#include <limits.h>

#define		BLANC		0
#define		GRIS		1
#define		NOIR		2
#define		INFINI		INT_MAX

typedef struct sommet {
	int id;
	int couleur;
	int distance;
	int date_d;
	int date_f;
	struct sommet* pere;
} sommet_t;

void initialiser_sommet_largeur(sommet_t* sommet, int id);
void initialiser_sommet_profondeur(sommet_t* sommet, int id);

#endif
