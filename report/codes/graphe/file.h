#ifndef __FILE_H__
#define __FILE_H__

#include "sommet.h"

/* tableau de pointeur sur une structure de sommet_t */
typedef struct file {
	int capacite;
	int tete;
	int queue;
	sommet_t** sommets;
} file_t;

void initialiser_file(file_t* file, int capacite);
void detruire_file(file_t* file);
int file_vide(file_t* file);
int file_pleine(file_t* file);
void enfiler(file_t* file, sommet_t* sommet);
sommet_t* defiler(file_t* file); /* sommmet_t** retour ?? */
void afficher_file(file_t* file);

#endif
