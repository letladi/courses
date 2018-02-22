#include "largeIntegers.h"
#include <iostream>

int main()
{
    largeIntegers one("3");
    largeIntegers two("255");
    largeIntegers sum = two + one;
    std::cout << sum;
}