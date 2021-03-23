default: app.o util.o
	gcc -o app app.o util.o
	rm app.o util.o

app.o: app.c 
	gcc -c app.c

util.o: ../../../util.h ../../../util.c
	gcc -c ../../../util.c ../../../util.h