build: main.o onegin.o string.o onegin_test.o
	gcc main.o onegin.o string.o onegin_test.o
	./a.out

main.o: main.c
	gcc -c main.c

onegin.o: onegin.c onegin.c
	gcc -c onegin.c

string.o: string.c
	gcc -c string.c

onegin_test.o: onegin_test.c
	gcc -c onegin_test.c

clean:
	rm -f *.o
	rm -f *.out