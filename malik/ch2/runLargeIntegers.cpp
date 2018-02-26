#include "largeIntegers.h"
#include <iostream>

int main()
{
    largeIntegers one("3");
    largeIntegers two("255");
    largeIntegers x = one;
    std::cout << x.getNumber() << std::endl;
}