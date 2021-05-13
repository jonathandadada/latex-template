#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cellule.h"
#include "liste.h"
#include "graphe.h"


void initialiser_graphe(graphe_t* graphe, char* str){
	char buffer[41];
	int tmp, i, nb_arretes = 0, fin = 0;
	liste_t l1, l2;
	cellule_t *c1, *c2, *tmp1, *tmp2;
	int **arretes;
	FILE* f;
	
	f = fopen(str,"r");
	fscanf(f,"%s %d",buffer,&(graphe->n_sommets));
	fscanf(f,"%s %d",buffer,&(graphe->oriente));
	fscanf(f,"%s %d",buffer,&(graphe->value));
	fscanf(f,"%s",buffer);
	
	/* remplacer par liste_t car on ne connait pas la nb_arretes avant le parcours */
	initialiser_liste(&l1);
	initialiser_liste(&l2);
	/*tab1 = (int*)malloc(sizeof(int)*(graphe->n_sommets));
	tab2 = (int*)malloc(sizeof(int)*(graphe->n_sommets));*/
	
	if(strcmp(buffer,"DEBUT_DEF_ARETES") == 0){
		while(fin == 0){
			fscanf(f,"%s",buffer);
			if(strcmp(buffer,"FIN_DEF_ARETES")){
				c1 = (cellule_t*)malloc(sizeof(cellule_t));
				creer_cellule(c1,atoi(buffer));
				inserer(&l1,c1);
				fscanf(f,"%d",&tmp);
				c2 = (cellule_t*)malloc(sizeof(cellule_t));
				creer_cellule(c2,tmp);
				inserer(&l2,c2);
				++nb_arretes;
			} else {
				fin = 1;
			}
		}
	}
	
	arretes = (int**)malloc(sizeof(int*)*nb_arretes);
	for(i = 0; i < nb_arretes; ++i){
		arretes[i] = (int*)malloc(sizeof(int)*2);
	}
	
	i=0;
	
	while(l1.tete != NULL){
		arretes[i][0] = l1.tete->cle;
		tmp1 = l1.tete;
		l1.tete = l1.tete->succ;
		free(tmp1);
		tmp1 = NULL;
		
		arretes[i][1] = l2.tete->cle;
		tmp2 = l2.tete;
		l2.tete = l2.tete->succ;
		free(tmp2);
		tmp2 = NULL;
		
		++i;
	}
	
	creer_liste_adj(graphe,arretes,nb_arretes);
	creer_matrice_adj(graphe,arretes,nb_arretes);
	
	for(i = 0; i < nb_arretes; ++i){
		free(arretes[i]);
	}
	
	free(arretes);
	fclose(f);
}

void creer_liste_adj(graphe_t* graphe, int** arretes, int nb_arretes){
	int i;
	cellule_t *cell1 = NULL, *cell2 = NULL;
	graphe->l_adj = (liste_t*)malloc(sizeof(liste_t)*graphe->n_sommets);
	
	for(i = 0; i < graphe->n_sommets; ++i){
		initialiser_liste(&graphe->l_adj[i]);
	} 
	
	for(i = 0; i < nb_arretes; ++i){
		cell1 = (cellule_t*)malloc(sizeof(cellule_t));
		creer_cellule(cell1,arretes[i][1]);
		inserer(&graphe->l_adj[arretes[i][0]],cell1);
		if(graphe->oriente == 0){
			cell2 = (cellule_t*)malloc(sizeof(cellule_t));
			creer_cellule(cell2,arretes[i][0]);
			inserer(&graphe->l_adj[arretes[i][1]],cell2);
		}
	}
}

void afficher_liste_adj(graphe_t* graphe){
	int i;
	printf("Listes d'adjacences : \n");
	for(i = 0; i < graphe->n_sommets; ++i){
		printf("%d --> ",i);
		afficher_liste(&graphe->l_adj[i]);
	}
	printf("\n");
}

void detruire_liste_adj(graphe_t* graphe){
	int i;
	for(i = 0; i < graphe->n_sommets; ++i){
		detruire_liste(&graphe->l_adj[i]);
	}
	free(graphe->l_adj);
}

void creer_matrice_adj(graphe_t* graphe, int** arretes, int nb_arretes){
	int i, j;
	graphe->m_adj = (int**)malloc(sizeof(int*)*graphe->n_sommets);
	for(i = 0; i < graphe->n_sommets; ++i){
		graphe->m_adj[i] = (int*)malloc(sizeof(int)*graphe->n_sommets);
	}
	
	for(i = 0; i < graphe->n_sommets; ++i){
		for(j = 0; j < graphe->n_sommets; ++j){
			graphe->m_adj[i][j] = 0;
		}
	}
	
	for(i = nb_arretes - 1; i >= 0; --i){
		graphe->m_adj[arretes[i][0]][arretes[i][1]] = 1;
		if(graphe->oriente == 0){
			graphe->m_adj[arretes[i][1]][arretes[i][0]] = 1;
		}
	}
}

void afficher_matrice_adj(graphe_t* graphe){
	int i, j;
	printf("Matrice d'adjacences : \n");
	for(i = 0; i < graphe->n_sommets; ++i){
		for(j = 0; j < graphe->n_sommets; ++j){
			printf("[%d]",graphe->m_adj[i][j]);
		}
		printf("\n");
	}
}

void detruire_matrice_adj(graphe_t* graphe){
	int i;
	for(i = 0; i < graphe->n_sommets; ++i){
		free(graphe->m_adj[i]);
	}
	free(graphe->m_adj);
}

void afficher_graphe(graphe_t* graphe){
	printf("Nombre de sommets : %d\n",graphe->n_sommets);
	if(graphe->oriente == 0){
		printf("Non oriente\n");
	} else {
		printf("Oriente\n");
	}
	if(graphe->value == 0){
		printf("Non value\n");
	} else {
		printf("Value\n");
	}
	afficher_liste_adj(graphe);
	afficher_matrice_adj(graphe);
}

void detruire_graphe(graphe_t* graphe){
	detruire_liste_adj(graphe);
	detruire_matrice_adj(graphe);
	free(graphe);
}
