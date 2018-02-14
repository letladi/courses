#include "pointType.h"
#include <iostream>

pointType::pointType() {
    setCoordinate(0, 0);
}

pointType::pointType(double startX, double startY) {
    setCoordinate(startX, startY);
}

void pointType::setCoordinate(double newX, double newY) {
    x = newX;
    y = newY;
}

void pointType::getCoordinates(double &xToGet, double &yToGet) const {
    xToGet = x;
    yToGet = y;
}

double pointType::getX() const {
    return x;
}

double pointType::getY() const {
    return y;
}

void pointType::setX(double newX) {
    x = newX;
}

void pointType::setY(double newY) {
    y = newY;
}

void pointType::print() const {
    std::cout << "(x, y) => (" << x << ", " << y << ")";
}