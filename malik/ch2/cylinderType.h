#include "circleType.h"

class cylinderType : public circleType {
public:
    void print() const;
    double volume() const;
    double surfaceArea() const;
    void setHeight(double);

    cylinderType(double x = 0, double y = 0, double r = 1, double h = 1);

private:
    double height;
};