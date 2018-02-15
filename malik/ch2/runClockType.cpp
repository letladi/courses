#include "clockType.h"
#include "../test.cpp"
#include <iostream>

int main() {
    suite("clockType operators");
    clockType clock1(5, 10);
    clockType clock2(5, 10, 1);

    assertEqual(true, clock1 < clock2, "two clocks can be equal or greater than");
}