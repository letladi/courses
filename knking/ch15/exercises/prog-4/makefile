default: remind.o readline.o
	gcc -o app remind.o readline.o

remind.o: remind.c
	gcc -c remind.c

readline.o: readline.c readline.h
	gcc -c readline.c
