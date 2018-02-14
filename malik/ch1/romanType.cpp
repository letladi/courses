#include "romanType.h"
#include <iostream>

romanType::romanType(std::string romanNum) 
{
    romanNum = romanNum;
    decimalNum = 0;
}

romanType::romanType() 
{
    romanNum = "";
    decimalNum = 0;
}

int romanType::getDecimalNum() 
{
    if (decimalNum == 0) {
        convertToDecimal();
    }
    return decimalNum;
}

std::string romanType::getRomanNum() const
{
    return romanNum;
}

void romanType::setRomanNum(std::string newRoman)
{
    romanNum = newRoman;
    decimalNum = 0;
}

void romanType::convertToDecimal()
{
    int prevNum = -1;
    int currNum;

    for(char& c : romanNum) {
        currNum = getDecimalForSymbol(c);
        decimalNum += currNum;

        if (prevNum > 0 && prevNum < currNum) 
            decimalNum -= prevNum * 2;

        prevNum = currNum;
    }
}

int romanType::getDecimalForSymbol(char& c) const
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



