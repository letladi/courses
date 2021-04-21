default: stackclient.o stackADT.o
	gcc -o app stackclient.o stackADT.o
	rm stackADT.o stackclient.o

stackADT.o: stackADT.h stackADT.c
	gcc -c stackADT.c stackADT.h 

stackclient.o: stackclient.c 
	gcc -c stackclient.c
	