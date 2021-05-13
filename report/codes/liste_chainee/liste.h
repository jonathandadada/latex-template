#ifndef __LISTE_H__
#define __LISTE_H__

typedef struct liste
{
    cellule_t* tete;
} liste_t;

int initialiser_liste(liste_t* l);
void inserer(liste_t* l, cellule_t* x);
/*liste_t* creer_liste(int* tab, int nb_elements);*/
void detruire_liste(liste_t* l);
void supprimer(liste_t* l, cellule_t* x);
cellule_t* rechercher(liste_t* l, int k);
void afficher_liste(liste_t* l);

#endif
