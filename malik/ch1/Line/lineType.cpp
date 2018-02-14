#include "lineType.h"
#include "../../../../../../Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1/array"
#include <limits>
#include <exception>

lineType::lineType(double initA, double initB, double initC) {
    a = initA;
    b = initB;
    c = initC;
}

double lineType::slope() {
    if (hasSlope() == false) return std::numeric_limits<double>::quiet_NaN();
    else if (a == 0) return 0;
    else return -a/b;
}

bool lineType::hasSlope() {
    return b != 0;
}

bool lineType::isParallel(lineType& otherLine) {
    return (a == 0 && otherLine.a == 0) || (b == 0 && otherLine.b == 0) || (slope() == otherLine.slope());
}

bool lineType::isPerpendicular(lineType& otherLine) {
    if (hasSlope() && otherLine.hasSlope()) {
        return (slope() * otherLine.slope()) == -1;
    } else if (isParallel(otherLine)) {
        return false;
    } else {
        return (a == 0 && otherLine.b == 0) || (b == 0 && otherLine.a == 0);
    }
    
}

bool lineType::equals(lineType& otherLine) {
    if (isParallel(otherLine)) {
        std::array<double, 2> slopeIntercept1 = slopeInterceptForm();
        std::array<double, 2> slopeIntercept2 = otherLine.slopeInterceptForm();

        return (slopeIntercept1[0] == slopeIntercept2[0]) && (slopeIntercept1[1] == slopeIntercept2[1]);
    } else {
        return false;
    }
}

std::array<double, 2> lineType::interSection(lineType& otherLine) {
    std::array<double, 2> result = { std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN() };
    if (isParallel(otherLine)) {
        return result;
    } 

    if (b == 0) {
        double x = c / a;
        result[0] = x;

        double y = -1 * (otherLine.a / otherLine.b) * x + otherLine.c / otherLine.b;
        result[1] = y;

        return result;
    } else if (otherLine.b == 0) {
        double x = otherLine.c / otherLine.a;
        result[0] = x;

        double y = -1 * (a / b) * x + c / b;
        result[1] = y;
        return result;
    }

    if (a == 0) {
        double y = c / b;
        result[1] = y;

        double x = (otherLine.c - otherLine.b * y) / otherLine.a; //c -(otherLine.c - otherLine.b) / otherLine.a;
        result[0] = x;
        return result;
    } else if (otherLine.a == 0) {
        double y = otherLine.c / otherLine.b;
        result[1] = y;

        double x = (c - b * y) / a;
        result[0] = x;
        return result;
    } else {
        std::array<double, 2> slopeInterceptForm1 = slopeInterceptForm();
        std::array<double, 2> slopeInterceptForm2 = otherLine.slopeInterceptForm();

        std::array<double, 2> calculatedValues = {slopeInterceptForm1[0] - slopeInterceptForm2[0], slopeInterceptForm2[1] - slopeInterceptForm1[1]};
        double x = calculatedValues[1] / calculatedValues[0];

        result[0] = x;
        result[1] = getY(x);

        return result;
    }
}

double lineType::getY(double x) {
    return (-1.0 * (a * x) + c) / b;
}
std::array<double, 2> lineType::slopeInterceptForm() {
    std::array<double, 2> result = { -1.0 * (a / b), c / b };
    return result;
}