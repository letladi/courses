default: app.o stack.o
	gcc -o app app.o stack.o

app.o: app.c
	gcc -c app.c

stack.o: stack.c stack.h
	gcc -c stack.c stack.h
