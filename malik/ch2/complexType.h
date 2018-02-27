#ifndef H_complexNumber
#define H_complexNumber

#include <iostream>

class complexType
{
    friend std::ostream& operator<<(std::ostream&, const complexType&);
    friend std::istream& operator<<(std::istream&, complexType&);
    friend complexType operator~(const complexType);
    friend double operator!(const complexType);
public:
    void setComplex(const double& real, const double& imag);
    void getComplex(double& real, double& imag) const;
    complexType(double real = 0, double imag = 0);
    complexType operator+(const complexType& c) const;
    complexType operator*(const complexType& c) const;
    complexType operator/(const complexType& c) const;
    complexType operator-(const complexType& c) const;
    complexType conjugate() const;
    bool operator==(const complexType& c) const;
private:
    double realPart;
    double imaginaryPart;
};

#endif
