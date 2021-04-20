default: stack_test.o stack.o
	gcc -o app stack_test.o stack.o

stack.o: ../stack.h stack.c
	gcc -c stack.c ../stack.h

stack_test.o: stack_test.c ../stack.h stack.c
	gcc -c stack_test.c stack.c

