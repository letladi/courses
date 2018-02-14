#include "pointType.h"

class circleType : public pointType
{
public:
    void setRadius(double);
    void print() const;
    double area() const;
    double circumference() const;
    void setCenter(double, double);
    void getCenter(double &x, double &y) const;
    circleType();
    circleType(double x, double y, double radius);
private:
    double r;
};