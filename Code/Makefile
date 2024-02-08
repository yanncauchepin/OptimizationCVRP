all : main.o tour_geant.o split.o bellman.o
	gcc -o ../cvrp *.o -Wall

tour_geant.o : tour_geant.h tour_geant.c
	gcc -c tour_geant.h tour_geant.c -Wall

split.o : split.h split.c
	gcc -c split.h split.c -Wall

bellman.o : bellman.h bellman.c
	gcc -c bellman.h bellman.c -Wall

main.o : tour_geant.h split.h bellman.h main.c
	gcc -c tour_geant.h split.h bellman.h main.c -Wall

clean :
	rm *.o *.gch ../cvrp
