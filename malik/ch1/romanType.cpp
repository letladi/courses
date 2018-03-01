#include "romanType.h"
#include <iostream>

romanType::romanType(std::string romanNum)
{
    setRomanNum(romanNum);
}

void romanType::setRomanNum(const std::string newRoman)
{
    romanNum = newRoman;
    decimalNum = romanToDecimal();
}

romanType::romanType(int n)
{
    setDecimalNum(n);
}

void romanType::setDecimalNum(const int n)
{
    decimalNum = n;
    romanNum = decimalToRoman();
}

int romanType::getDecimalNum() const
{
    return decimalNum;
}

int romanType::romanToDecimal() const
{
    int prevNum = -1;
    int currNum;
    int result = 0;

    for(const char& c : romanNum) {
        currNum = getDecimalForSymbol(c);
        result += currNum;

        if (prevNum > 0 && prevNum < currNum)
            result -= prevNum * 2;

        prevNum = currNum;
    }
    return result;
}

std::string romanType::decimalToRoman() const
{
    int n = decimalNum;
    std::string result("");
    while (n > 0)
    {
        if (n >= 1000) {
            result += getSymbolForDecimal(1000);
            n -= 1000;
        } else if (n >= 500) {
            result += getSymbolForDecimal(500);
            n -= 500;
        } else if (n >= 100) {
            result += getSymbolForDecimal(100);
            n -= 100;
        } else if (n >= 50) {
            result += getSymbolForDecimal(50);
            n -= 50;
        } else if (n >= 10) {
            result += getSymbolForDecimal(10);
            n -= 10;
        } else if (n == 4 || n == 5 || n == 9) {
            result += getSymbolForDecimal(n);
            n -= n;
        } else if (n >= 5) {
            result += getSymbolForDecimal(5);
            n -= 5;
        } else {
            result += getSymbolForDecimal(1);
            n--;
        }
    }
    return result;
}

std::string romanType::getSymbolForDecimal(const int n) const
{
    switch(n) {
        case 1000: return "M";
        case 500: return "D";
        case 100: return "C";
        case 50: return "L";
        case 10: return "X";
        case 9: return "IX";
        case 5: return "V";
        case 4: return "IV";
        case 1: return "I";
        default: return "";
    }
}

int romanType::getDecimalForSymbol(const char& c) const
{
    switch(c) {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default: return 0;
    }
}

std::string romanType::getRomanNum() const
{
    return romanNum;
}

std::ostream& operator<<(std::ostream& os, romanType& rome)
{
    os << std::endl << "Roman: " << rome.getRomanNum() << "(" << rome.romanToDecimal() << ")" << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, romanType& rome)
{
    std::cout << "Please input a roman numeral number: ";

    std::string input;
    is >> input;
    rome.setRomanNum(input);
    return is;
}
