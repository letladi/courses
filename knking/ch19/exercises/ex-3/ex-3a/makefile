default: queue_test.o queue.o
	gcc -o app queue_test.o queue.o

queue.o: ../../ex-1/queue.h queue.c
	gcc -c queue.c ../../ex-1/queue.h 

queue_test.o: ../queue_test.c ../../ex-1/queue.h queue.c
	gcc -c ../queue_test.c queue.c
