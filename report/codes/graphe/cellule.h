#ifndef __CELLULE_H__
#define __CELLULE_H__

typedef struct cell
{
	struct cell* pred;
	struct cell* succ;
	int cle;
} cellule_t;

void creer_cellule(cellule_t* c, int val);
void detruire_cellule(cellule_t** c);

#endif
