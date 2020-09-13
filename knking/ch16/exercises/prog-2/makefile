default: inventory.o readline.o
	gcc -o app inventory.o readline.o

inventory.o: inventory.c
	gcc -c inventory.c

readline.o: readline.c readline.h
	gcc -c readline.c readline.h
