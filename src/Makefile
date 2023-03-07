CCOPTIONS	= -Wall -g
CC			= g++ $(CCOPTIONS)

prog: main.o grille.o vehicule.o
	$(CC) main.o grille.o vehicule.o -o prog

vehicule.o: vehicule.cpp vehicule.hpp
	$(CC) -c vehicule.cpp

grille.o: grille.cpp grille.hpp vehicule.hpp
	$(CC) -c grille.cpp

main.o: main.cpp vehicule.hpp grille.hpp
	$(CC) -c main.cpp

clean:
	rm -rf *.o prog
