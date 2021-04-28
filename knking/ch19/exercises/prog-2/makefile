default: prog-6.o stackADT.o
	gcc -o app prog-6.o stackADT.o
	rm stackADT.o prog-6.o

stackADT.o: stackADT.h stackADT.c
	gcc -c stackADT.c stackADT.h 

stackclient.o: prog-6.c 
	gcc -c prog-6.c
	