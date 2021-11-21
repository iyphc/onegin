build: main.o onegin.o string.o
	gcc main.o onegin.o string.o 
	./a.out

main.o: main.c
	gcc -c main.c

onegin.o: onegin.c onegin.c
	gcc -c onegin.c

string.o: string.c
	gcc -c string.c

clean:
	rm -f *.o
	rm -f *.out


