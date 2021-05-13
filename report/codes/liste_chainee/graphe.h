#ifndef __GRAPHE_H__
#define __GRAPHE_H__

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

/*graphe_t* initialiser_graphe(char* fichier);*/

#endif //__GRAPHE_H__
