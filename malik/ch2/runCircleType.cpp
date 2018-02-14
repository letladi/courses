#include "circleType.h"
#include <iostream>

int main() {
    circleType circle(2, 2, 5);

    circle.printRadius();
    std::cout << "circle area: " << circle.area() << std::endl;
}