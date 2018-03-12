#include "polynomialType.h"
#include <cmath>

polynomialType::polynomialType(int size) : arrayListType<double>(size)
{
    length = size;
    for (int i = 0; i < size; i++) list[i] = 0;
}

double polynomialType::operator()(double x)
{
    double value = 0.0;
    for (int i = 0; i < length; i++)
    {
        if (list[i] != 0.0) {
            value = value + list[i] * pow(x, i);
        }
    }
    return value;
}

polynomialType polynomialType::operator+(const polynomialType& other)
{
    int size = max(length, other.length);
    polynomialType result(size);

    for (int i = 0, terms = min(length, other.length); i < terms; i++) {
        result.list[i] = list[i] + other.list[i];
    }

    if (size == length) {
        for (int i = min(length, other.length); i < length; i++) result.list[i] = list[i];
    } else {
        for (int i = min(length, other.length); i < other.length; i++) result.list[i] = other.list[i];
    }

    return result;
}

polynomialType polynomialType::operator-(const polynomialType& other)
{
    int size = max(length, other.length);
    polynomialType result(size);

    for (int i = 0, terms = min(length, other.length); i < terms; i++) {
        result.list[i] = list[i] - other.list[i];
    }

    if (size == length) {
        for (int i = min(length, other.length); i < length; i++)
            result.list[i] = list[i];
    } else {
        for (int i = min(length, other.length); i < other.length; i++)
            result.list[i] = -1 * other.list[i];
    }
    return result;
}

int polynomialType::min(int x, int y) const
{
    return (x <= y) ? x : y;
}

int polynomialType::max(int x, int y) const
{
    return (x >= y) ? x : y;
}

ostream& operator<<(ostream& os, const polynomialType& p)
{
    int indexFirstNonZeroCoeff = 0;

    for (int i = 0; i < p.length; i++) {
        if (p.list[i] != 0.0) {
            indexFirstNonZeroCoeff = i;
            break;
        }
    }

    if (indexFirstNonZeroCoeff < p.length) {
        if (indexFirstNonZeroCoeff == 0) {
            os << p.list[indexFirstNonZeroCoeff] << " ";
        } else {
            os << p.list[indexFirstNonZeroCoeff] << "x^" << indexFirstNonZeroCoeff << " ";
        }

        for (int i = indexFirstNonZeroCoeff + 1; i < p.length; i++) {
            if (p.list[i] != 0.0) {
                os << ((p.list[i] >= 0.0) ? "+ " : "- ") << p.list[i] << "x^" << i << " ";
            }
        }
    } else {
        os << "0";
    }

    return os;
}

istream& operator>>(istream& is, polynomialType& p)
{
    cout << "The degree of this polynomial is: " << p.length - 1 << endl;

    for (int i = 0; i < p.length; i++) {
        cout << "Enter the coefficients of x^" << i << ": ";
        is >> p.list[i];
    }
    return is;
}
