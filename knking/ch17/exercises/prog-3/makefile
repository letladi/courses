default: inventory2.o util.o
	gcc inventory2.o util.o

inventory.o:  inventory2.c 
	gcc -c inventory2.c

util.o: ../../../util.c ../../../util.h
	gcc -c ../../../util.c ../../../util.h