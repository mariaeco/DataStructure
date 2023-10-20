all: main

main: main.o hashv.o
	gcc main.o hashv.o -o main

main.o: main.c hashv.h
	gcc -c main.c -o main.o

hashv.o: hashv.c hashv.h
	gcc -c hashv.c -o hashv.o

clean:
	rm -f *.o main