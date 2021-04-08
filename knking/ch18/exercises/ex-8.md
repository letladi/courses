a) x is an array of 10 of 10 function pointers, each of which takes an integer as an argument and returns a char.
   # x is an array of ten pointers to functions. Each function takes an int argument and returns a character.
b) x is an array of 5 function pointers, each of which takes an int and returns an int.
   # x is a function that returns a pointer to an array of five integers.
c) x is a pointer to a function pointer that takes no argument.
   x returns a function pointer that takes an int and returns a float.
   # x is a funcion with no arguments that returns a pointer to a function with an int argument that returns a pointer to a float value

d) x is a function pointer that returns a function pointer that takes an int and returns void.
   x itself takes an int, and a function pointer that returns void and takes an int as an argument.
   # x is a function with two arguments. The first argument is an integer, and the second is a pointer to a function with an int argument and no return value. x returns a pointer to a function with an int argument and no return value. (Although this example may seem artificially complex, the signal function- part of the Standard C library- has exactly this prototype)

   