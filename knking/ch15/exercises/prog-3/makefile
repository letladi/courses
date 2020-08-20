sort: sort.o quicksort.o
	gcc -o sort sort.o quicksort.o

sort.o: sort.c
	gcc -c sort.c

# qsort: quicksort.o
# 	gcc -o quicksort quicksort.o

quicksort.o: quicksort.c quicksort.h
	gcc -c quicksort.c
