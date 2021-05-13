#ifndef __GRAPHE_H__
#define __GRAPHE_H__

#include "liste.h"
#include "file.h"
#include "pile.h"

typedef struct graphe {
	int n_sommets;
	int oriente;
	int value;
	liste_t* l_adj;
	int** m_adj;
} graphe_t;

void initialiser_graphe(graphe_t* graphe, char* str);
void creer_matrice_adj(graphe_t* graphe, int** arretes, int nb_arretes);
void afficher_liste_adj(graphe_t* graphe);
void detruire_liste_adj(graphe_t* graphe);
void creer_liste_adj(graphe_t* graphe, int** arretes, int nb_arretes);
void afficher_matrice_adj(graphe_t* graphe);
void detruire_matrice_adj(graphe_t* graphe);
void afficher_graphe(graphe_t* graphe);
void detruire_graphe(graphe_t* graphe);

void parcours_largeur_matrice(graphe_t* graphe, sommet_t* sommets, sommet_t* s);
void parcours_largeur_liste(graphe_t* graphe, sommet_t* sommets, sommet_t* s);
void afficher_chemin(graphe_t* graphe, sommet_t* s, sommet_t* v);

void parcours_profondeur_matrice(graphe_t* graphe, sommet_t* sommets);
void visiter_pp_matrice(graphe_t* graphe, sommet_t* sommets, sommet_t* u, int* date);
//void parcours_profondeur_liste(graphe_t* graphe, sommet_t* sommets);
//void visiter_pp_liste(graphe_t* graphe, sommet_t* sommets, sommet_t* u, int* date);
void afficher_parcours_profondeur(graphe_t* graphe, sommet_t* sommets);
void parcours_profondeur_iteratif(graphe_t* graphe, sommet_t* sommets); /* le deuxieme du cours */

#endif //__GRAPHE_H__
