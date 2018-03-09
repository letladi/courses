#include "arrayListType.h"

class polynomialType: public arrayListType<double>
{
    friend ostream& operator<<(ostream&, const polynomialType&);
    friend istream& operator>>(istream&, polynomialType&);
public:
    polynomialType operator+(const polynomialType&);
    polynomialType operator-(const polynomialType&);
    polynomialType operator*(const polynomialType&);
    double operator()(double x);
    polynomialType(int size = 100);
    int min(int x, int y) const;
    int max(int x, int y) const;
};
