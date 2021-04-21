default: queue_test.o queue.o
	gcc -o app queue_test.o queue.o

queue.o: queue.h queue.c
	gcc -c queue.c queue.h 

queue_test.o: queue_test.c queue.h queue.c
	gcc -c queue_test.c queue.c