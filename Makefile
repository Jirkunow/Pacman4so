pacman: ghost.o pacman.o main.o
	gcc ghost.o pacman.o main.o -o pacman -lncurses -lpthread -lm 

Main.o : main.c
	gcc -c main.c -o main.o

pacman.o: pacman.c pacman.h
	gcc -c pacman.c -o pacman.o -lncurses -lpthread -lm 


ghost.o: ghost.c ghost.h
	gcc -c ghost.c -o ghost.o -lncurses -lpthread -lm 

Clean:
	rm pacman
	rm *.o
