default: prog-1.o stackADT.o
	gcc -o app prog-1.o stackADT.o
	rm stackADT.o prog-1.o

stackADT.o: stackADT.h stackADT.c
	gcc -c stackADT.c stackADT.h 

stackclient.o: prog-1.c 
	gcc -c prog-1.c
	