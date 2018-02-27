#include "fractionType.h"
#include <iostream>

int main()
{
    fractionType fr(2, 3);
    fractionType fr2(5, 2);
    std::cout << fr + fr2;
}
