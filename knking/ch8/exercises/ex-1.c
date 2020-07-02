/*
   a[0] refers to the actual size of the element a[0], sizeof(a) also refers 
   to the actual size of a, so the the results of the two sizeof() operators
   use accurate values.
   A: sizeof(t) can't easily be checked for correctness by someone reading the program
   They would have to locate the declaration of 'a' to ensure its type is actually t
*/