#include "cylinderType.h"
#include <math.h>
#include <iostream>

cylinderType::cylinderType(double x, double y, double r, double h) : circleType(x, y, r) {
    height = h;
}
void cylinderType::setHeight(double newH) {
    height = newH;
}

double cylinderType::surfaceArea() const {
    return circumference() * height + area() * 2;
}

double cylinderType::volume() const {
    return area() * height;
}

void cylinderType::print() const {
    circleType::print();
    std::cout << "height = " << height << std::endl;
    std::cout << "volume = " << volume() << std::endl;
    std::cout << "surface area = " << surfaceArea() << std::endl;
}


