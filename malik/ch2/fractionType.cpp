#include "fractionType.h"
#include <limits>

fractionType::fractionType(double dividendInit, double divisorInit)
{
    dividend = dividendInit;
    divisor = divisorInit;
}

void fractionType::setDivisor(double val)
{
    divisor = val;
}

void fractionType::setDividend(double val)
{
    dividend = val;
}

void fractionType::getFraction(double& dividendVal, double& divisorVal) const
{
    dividendVal = dividend;
    divisorVal = divisor;
}

std::ostream& operator<<(std::ostream& os, const fractionType& fr)
{
    os << std::endl << "Fraction: " << fr.dividend << " / " << fr.divisor << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, fractionType& fr)
{
    std::string input, divisorString = "", dividendString = "";
    std::cout << std::endl << "Please enter a fraction in the form 'm/n': ";
    is >> input;
    std::cout << std::endl;

    const double len = input.length();
    int i = 0;
    for ( ; i < len; i++)
        if (input[i] != '/') dividendString += input[i];
        else {
            i++;
            break;
        }

    double dividend, divisor;

    if (i == len) divisorString = "0";
    else
        for ( ; i < len; i++)
            divisorString += input[i];

    divisor = stod(divisorString);
    dividend = stod(dividendString);

    fr.setDivisor(divisor);
    fr.setDividend(dividend);

    return is;
}

fractionType fractionType::operator+(const fractionType& fr) const
{
    double a, b, c, d;
    getFraction(a, b);
    fr.getFraction(c, d);

    fractionType result(a * d + b * c, b * d);
    return result;
}

fractionType fractionType::operator-(const fractionType& fr) const
{
    double a, b, c, d;
    getFraction(a, b);
    fr.getFraction(c, d);

    fractionType result(a * d - b * c, b * d);
    return result;
}

fractionType fractionType::operator*(const fractionType& fr) const
{
    double a, b, c, d;
    getFraction(a, b);
    fr.getFraction(c, d);

    fractionType result(a * c, b * d);
    return result;
}

fractionType fractionType::operator/(const fractionType& fr) const
{
    double a, b, c, d;
    getFraction(a, b);
    fr.getFraction(c, d);

    fractionType result(a * d, b * c);
    return result;
}

bool fractionType::operator<(const fractionType& fr) const
{
    double a, b, c, d;
    getFraction(a, b);
    fr.getFraction(c, d);
    return (a * d) < (b * c);
}

bool fractionType::operator>(const fractionType& fr) const
{
    double a, b, c, d;
    getFraction(a, b);
    fr.getFraction(c, d);
    return (a * d) > ( b * c);
}

bool fractionType::operator==(const fractionType& fr) const
{
    double a, b, c, d;
    getFraction(a, b);
    fr.getFraction(c, d);
    return (a * d) == (b * c);
}
