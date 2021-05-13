CC=gcc -Wall -O3 -g
OBJETS= main.o graphe.o liste.o cellule.o

prog_graphe: $(OBJETS)
	$(CC) -o prog_graphe $(OBJETS)
main.o: main.c graphe.h
	$(CC) -c main.c
graphe.o: graphe.c graphe.h liste.h
	$(CC) -c graphe.c
liste.o: liste.c liste.h cellule.h
	$(CC) -c liste.c
cellule.o: cellule.c cellule.h
	$(CC) -c cellule.c

clean:
	rm -f prog_graphe *.o
