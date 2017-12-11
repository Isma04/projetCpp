# options de compilation
CC = g++
CCFLAGS = -Wall -I -g -std=c++11 sdl-config --cflags --libs



# fichiers du projet
SRC = main.cc joueur.cc fond.cc
OBJ = $(SRC:.c=.o)
EXEC = main


# règle initiale
all: $(EXEC)

# dépendance des .hh
joueur.o: personnage.hh joueur.hh
fond.o: fond.hh Elem.hh

# règles de compilation
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

# règles d'édition de liens
$(EXEC): $(OBJ)
	$(CC) -o $@ $^  $(CCFLAGS)


# règles supplémentaires
clean:
	rm -f *.o
rmproper:
	rm -f $(EXEC) *.o
