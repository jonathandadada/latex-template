CC=gcc -Wall -O3 -g
OBJETS= prog_graphe.o graphe.o pile.o file.o liste.o sommet.o cellule.o

prog_graphe: $(OBJETS)
	$(CC) -o prog_graphe $(OBJETS)
prog_graphe.o: prog_graphe.c graphe.h liste.h file.h pile.h
	$(CC) -c prog_graphe.c
graphe.o: graphe.c graphe.h liste.h pile.h
	$(CC) -c graphe.c
pile.o: pile.c pile.h sommet.h
	$(CC) -c pile.c
file.o: file.c file.h sommet.h
	$(CC) -c file.c
liste.o: liste.c liste.h cellule.h
	$(CC) -c liste.c
sommet.o: sommet.c sommet.h
	$(CC) -c sommet.c
cellule.o: cellule.c cellule.h
	$(CC) -c cellule.c

clean:
	rm -f prog_graphe *.o
run: prog_graphe
	./prog_graphe graphe2.txt

