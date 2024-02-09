all : main.o giant_tour.o split.o bellman.o
	gcc -o ../cvrp *.o -Wall

giant_tour.o : giant_tour.h giant_tour.c
	gcc -c giant_tour.h giant_tour.c -Wall

split.o : split.h split.c
	gcc -c split.h split.c -Wall

bellman.o : bellman.h bellman.c
	gcc -c bellman.h bellman.c -Wall

main.o : giant_tour.h split.h bellman.h main.c
	gcc -c giant_tour.h split.h bellman.h main.c -Wall

clean :
	rm *.o *.gch ../cvrp
