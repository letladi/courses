#include <string>
#include <array>
#include <iostream>

class lineType {
    friend std::ostream& operator<<(std::ostream& os, lineType& line);
    friend std::istream& operator>>(std::istream& is, lineType& line);
public:
    lineType(double a = 0, double b = 0, double c = 0);
    lineType(const lineType& line);
    double slope() const;
    bool operator==(lineType& otherLine);
    bool operator||(lineType& otherLine);
    bool operator&&(lineType& otherLine);
    std::array<double, 2> interSection(lineType& otherLine);
    std::array<double, 2> slopeInterceptForm();
    lineType& operator=(const lineType& line);
    bool operator+() const;
    bool operator-() const;
private:
    double a;
    double b;
    double c;
    bool hasSlope() const;
    double getY(double x);
};
