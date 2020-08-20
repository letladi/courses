/**
 * a) f1.c f2.c main.c ✔️
 * b) f2.c main.c ❌ main only include headers, not source files, thus only f1.c is affected by the change
 * c) f1.c f2.c main.c ✔️
 * d) f1.c f2.c ✔️
 */ 