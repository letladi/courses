/**
 * b) function definitions should not be put in header files
 * It is a convention to place MACROS definitions, function prototypes
 * and type definitions in header files and then to place function definitions
 * in source files.
 * ❌ If a function definition appears in a header file that is included by two (or more)
 * source files, the program can't be linked, since the linker will see two copies of the function.
 */ 