#include "complexType.h"
#include <math.h>

std::ostream& operator<<(std::ostream& os, const complexType& complex)
{
    double real, imaginary;
    complex.getComplex(real, imaginary);
    os << "(" << real << ", " << imaginary << ")";
    return os;
}

std::istream& operator>>(std::istream& is, complexType& complex)
{
    char ch;
    double real, imaginary;
    is >> ch >> real >> ch >> imaginary >> ch;
    complex.setComplex(real, imaginary);
    return is;
}

bool complexType::operator==(const complexType& otherComplex) const 
{
    return (realPart == otherComplex.realPart && imaginaryPart == otherComplex.imaginaryPart);
}

complexType::complexType(double real, double imag)
{
    realPart = real;
    imaginaryPart = imag;
}

void complexType::setComplex(const double& real, const double& imag)
{
    realPart = real;
    imaginaryPart = imag;
}

void complexType::getComplex(double& real, double& imag) const 
{
    real = realPart;
    imag = imaginaryPart;
}

complexType complexType::operator+(const complexType& c) const
{
    complexType result;
    result.realPart = realPart + c.realPart;
    result.imaginaryPart = imaginaryPart + c.imaginaryPart;
    return result;
}

complexType complexType::operator*(const complexType& c) const 
{
    complexType result;
    result.realPart = (realPart * c.realPart) - (imaginaryPart * c.imaginaryPart);
    result.imaginaryPart = (realPart * c.imaginaryPart) + (imaginaryPart * c.realPart);
    return result;
}

complexType complexType::operator/(const complexType& c) const
{
    complexType temp;

    if (c.realPart == 0 || c.imaginaryPart == 0) return temp;

    const double cSquaredPlusDSquared = (c.realPart * c.realPart + c.imaginaryPart * c.imaginaryPart);

    temp.realPart = (realPart * c.realPart + imaginaryPart * c.imaginaryPart) / cSquaredPlusDSquared;
    temp.imaginaryPart = ( -1.0 * realPart * c.imaginaryPart + imaginaryPart * c.realPart) / cSquaredPlusDSquared;
    return temp;
}

complexType complexType::operator-(const complexType& c) const 
{   
    complexType result;
    result.realPart = realPart - c.realPart;
    result.imaginaryPart = imaginaryPart - c.imaginaryPart;

    return result;
}

complexType complexType::conjugate() const 
{
    complexType result(realPart, -1 * imaginaryPart);
    return result;
}

complexType operator~(const complexType c)
{
    return c.conjugate();
}

double operator!(const complexType c) 
{
    double aSquared = c.realPart * c.realPart;
    double bSquared = c.imaginaryPart * c.imaginaryPart;
    return sqrt( aSquared + bSquared);
}