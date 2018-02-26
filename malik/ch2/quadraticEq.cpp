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

bool quadraticEq::hasReadRoots() const
{
    return discriminant() >= 0;
}

void quadraticEq::realRoots(double& x1, double& x2) const
{
    const double disc = discriminant();
    x1 = ( -1 * b - sqrt(disc)) / (2 * a);
    x2 = (-1 * b + sqrt(disc)) / (2 * a);
}
