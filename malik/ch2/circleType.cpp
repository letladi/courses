#include "circleType.h"
#include <math.h>
#include <iostream>

circleType::circleType() {
    r = 1;
}

circleType::circleType(double x, double y, double radius) : pointType(x, y) {
    r = radius;
}

void circleType::setRadius(double newRadius) {
    r = newRadius;
}

void circleType::print() const {
    pointType::print();
    std::cout << ", r => " << r << std::endl;
}

double circleType::area() const {
    return M_PI * r * r;
}

double circleType::circumference() const {
    return 2 * M_PI * r;
}

void circleType::setCenter(double x, double y) {
    setCoordinate(x, y);
}

void circleType::getCenter(double &x, double &y) const {
    getCoordinates(x, y);
}
