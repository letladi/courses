#include "extRomanType.h"
#include <cmath>

extRomanType::extRomanType(std::string init) : romanType(init) {}

extRomanType::extRomanType(int init) : romanType(init) {}

extRomanType extRomanType::operator+(const extRomanType& other) const
{
    int x = romanToDecimal();
    int y = other.romanToDecimal();
    int sum = x + y;
    extRomanType result(sum);
    return result;
}

extRomanType extRomanType::operator-(const extRomanType& other) const
{
    int x = romanToDecimal();
    int y = other.romanToDecimal();
    int difference = std::abs(x - y);
    extRomanType result(difference);
    return result;
}

extRomanType extRomanType::operator*(const extRomanType& other) const
{
    int x = romanToDecimal();
    int y = other.romanToDecimal();
    int product = x * y;
    extRomanType result(product);
    return result;
}

extRomanType extRomanType::operator/(const extRomanType& other) const
{
    int x = romanToDecimal();
    int y = other.romanToDecimal();
    int quotient = x / y;
    extRomanType result(quotient);
    return result;
}

extRomanType& extRomanType::operator++()
{
    int n = romanToDecimal();
    n++;
    setDecimalNum(n);
    return *this;
}

extRomanType extRomanType::operator++(int)
{
    extRomanType before(romanToDecimal());
    operator++();
    return before;
}

extRomanType& extRomanType::operator--()
{
    int n = romanToDecimal();
    n--;
    setDecimalNum(n);
    return *this;
}

extRomanType extRomanType::operator--(int)
{
    extRomanType before(romanToDecimal());
    operator--();
    return before;
}
