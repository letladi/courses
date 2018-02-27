#include <iostream>
#include "complexType.h"

class quadraticEq
{
    friend std::ostream& operator<<(std::ostream& os, const quadraticEq& eq);
    friend std::istream& operator>>(std::istream& is, quadraticEq& eq);
public:
    quadraticEq(double a, double b, double c);
    void getCoefficients(double& a, double& b, double& c);
    quadraticEq operator+(const quadraticEq& other) const;
    quadraticEq operator-(const quadraticEq& other) const;
    bool operator==(const quadraticEq& other) const;
    bool operator!=(const quadraticEq& other) const;
    double discriminant() const;
    bool hasRealRoots() const;
    void realRoots(double& x1, double& x2) const;
    double root() const;
    void complexRoots(complexType& c1, complexType& c2) const;
private:
    double a;
    double b;
    double c;
};
