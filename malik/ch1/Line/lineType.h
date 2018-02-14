#include <string>
#include <array>
class lineType {
public:
    lineType(double a = 0, double b = 0, double c = 0);
    double slope();
    bool equals(lineType& otherLine);
    bool isParallel(lineType& otherLine);
    bool isPerpendicular(lineType& otherLine);
    std::array<double, 2> interSection(lineType& otherLine);
    std::array<double, 2> slopeInterceptForm();
    
private:
    double a;
    double b;
    double c;
    bool hasSlope();
    double getY(double x);
};