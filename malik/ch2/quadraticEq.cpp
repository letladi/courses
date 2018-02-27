#include "quadraticEq.h"
#include <math.h>

quadraticEq::quadraticEq(double a_init, double b_init, double c_init)
{
    a = a_init;
    b = b_init;
    c = c_init;
}

void quadraticEq::getCoefficients(double& a_to_set, double& b_to_set, double& c_to_set)
{
    a_to_set = a;
    b_to_set = b;
    c_to_set = c;
}

quadraticEq quadraticEq::operator+(const quadraticEq& other) const
{
    quadraticEq result(a + other.a, b + other.b, c + other.c);
    return result;
}

quadraticEq quadraticEq::operator-(const quadraticEq& other) const
{
    quadraticEq result(a - other.a, b - other.b, c - other.c);
    return result;
}

bool quadraticEq::operator==(const quadraticEq& other) const
{
    return a == other.a && b == other.b && c == other.c;
}

bool quadraticEq::operator!=(const quadraticEq& other) const
{
    return ((*this) == other) == false;
}

std::ostream& operator<<(std::ostream& os, const quadraticEq& eq)
{
    os << "a: " << eq.a << ", b: " << eq.b << ", c: " << eq.c << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, quadraticEq& eq)
{
    std::cout << std::endl << "Please input the 3 coefficients a, b and c: ";
    is >> eq.a >> eq.b >> eq.c;
    std::cout << std::endl;
    return is;
}

double quadraticEq::discriminant() const
{
    return pow(b, 2) - 4 * a * c;
}

bool quadraticEq::hasRealRoots() const
{
    return discriminant() >= 0;
}

void quadraticEq::realRoots(double& x1, double& x2) const
{
    const double disc = discriminant();
    const double divisor = 2 * a;
    x1 = ( -1 * b - sqrt(disc)) / divisor;
    x2 = (-1 * b + sqrt(disc)) / divisor;
}

void quadraticEq::complexRoots(complexType& c1, complexType& c2) const
{
    const double disc = discriminant();
    const double divisor = 2 * a;
    const double realNum = (-1 * b) / divisor;
    const double imaginaryNum = sqrt(fabs(disc)) / divisor;

    c1.setComplex(realNum, -1 * imaginaryNum);
    c2.setComplex(realNum, imaginaryNum);
}

double quadraticEq::root() const
{
    return (-1 * b) / (2 * a);
}
