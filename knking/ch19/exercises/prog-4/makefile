default: stackclient.o stackADT.o
	gcc -o app stackclient.o stackADT.o

stackADT.o: stackADT.c stackADT.h
	gcc -c stackADT.c stackADT.h

stackclient.o: stackclient.c
	gcc -c stackclient.c