#include <stdlib.h>
#include <stdio.h>

#include "file.h"

void initialiser_file(file_t* file, int capacite) {
	int i;
	file->capacite = capacite + 1;
	file->tete = 0;
	file->queue = 0;
	file->sommets = (sommet_t**)malloc(sizeof(sommet_t*)*(capacite + 1));
	for(i = 0; i < capacite + 1; ++i){
		file->sommets[i] = NULL;
	}
}

void detruire_file(file_t* file){
	free(file->sommets);
}

int file_vide(file_t* file){
	return file->tete == file->queue;
}

int file_pleine(file_t* file){
	int tmp = file->tete;
	if(tmp == 0){
		tmp = file->capacite - 1;
	} else {
		--tmp;
	}
	return tmp == file->queue;
}

void enfiler(file_t* file, sommet_t* sommet){
	if(!file_pleine(file)){
		file->sommets[file->queue] = sommet;
		if(file->queue == (file->capacite - 1)){
			file->queue = 0;
		} else {
			file->queue = file->queue + 1;
		}
	} else {
		printf("impossible d'enfiler, la file est pleine\n");
	}
}

sommet_t* defiler(file_t* file){ /* sommet_t** retour ?? */
	sommet_t* tmp = NULL;
	if(!file_vide(file)){
		tmp = file->sommets[file->tete];
		if(file->tete == (file->capacite - 1)){
			file->tete = 0;
		} else {
			file->tete = file->tete + 1;
		}
	} else {
		printf("impossible de defiler, la file est vide\n");
	}
	return tmp;
}

void afficher_file(file_t* file){
	int tmp = file->tete;
	if(file != NULL){
		if(!file_vide(file)){
			while(tmp != file->queue){
				printf("{%d,%d,%d,%d}\n",file->sommets[tmp]->id,file->sommets[tmp]->couleur,file->sommets[tmp]->distance,file->sommets[tmp]->pere->id);
				if(tmp != (file->capacite - 1)){
					++tmp;
				} else {
					 tmp = 0;
				}
			}
		}
	}
}
