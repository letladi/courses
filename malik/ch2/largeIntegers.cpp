#include "largeIntegers.h"

largeIntegers::largeIntegers() {
    setNumbers("0");
}

largeIntegers::largeIntegers(std::string init, bool positive) {
    setNumbers(init);
    isPositive = positive;
}

void largeIntegers::setNumbers(std::string newNumberString)
{
    numberString = newNumberString;

    numbers = {};
    length = newNumberString.length();
    length = 0;
    for (char& c: numberString) {
        numbers[length++] = intVal(c);
    }
}

std::istream& operator>>(std::istream& is, largeIntegers& integer)
{
    std::cout << "Please input a large integer with less than 100 characters: ";

    std::string input;
    std::cin >> input;

    integer.setNumbers(input);
    return is;
}

std::ostream& operator<<(std::ostream& os, largeIntegers& integer)
{
    std::cout << "Large Integer: ";
    for (int i = 0; i < integer.length; i++) std::cout << integer.numbers[i];
    std::cout << std::endl;
    return os;
}

int largeIntegers::intVal(char& c) const
{
    return c - '0';
}

largeIntegers largeIntegers::operator+(largeIntegers& other) const
{   
    const bool numbersHaveDifferentSigns = (isPositive && other.isPositive == false) || (isPositive == false && other.isPositive);
    
    if (numbersHaveDifferentSigns) 
        return (*this) -other;

    std::array<int, 100> longer;
    std::array<int, 100> shorter;
    int shorterLength;
    int longerLength;

    if (length >= other.length) {
        longer = numbers;
        longerLength = length;

        shorter = other.numbers;
        shorterLength = other.length;
    } else {
        longer = other.numbers;
        longerLength = other.length;

        shorter = numbers;
        shorterLength = length;
    }

    std::string sum = "";
    int currentSum = 0;
    int carryOver = 0;
    while (shorterLength > 0)
    {
        currentSum = carryOver + longer[--longerLength] + shorter[--shorterLength];

        if (currentSum >= 10)
        {
            currentSum -= 10;
            carryOver = 1;
        } else {
            carryOver = 0;
        }
        sum = std::to_string(currentSum) + sum;
    }

    while (longerLength > 0)
    {
        currentSum = carryOver + longer[--longerLength];
        carryOver = 0;
        sum = std::to_string(currentSum) + sum;
    }

    bool hasPositiveSign = (isPositive && other.isPositive);
    largeIntegers newLargeInt(sum, hasPositiveSign);
    return newLargeInt;
}

largeIntegers largeIntegers::operator-(largeIntegers& other) const
{
    std::array<int, 100> longer;
    std::array<int, 100> shorter;
    int shorterLength;
    int longerLength;

    if (length >= other.length) {
        longer = numbers;
        longerLength = length;

        shorter = other.numbers;
        shorterLength = other.length;
    } else {
        longer = other.numbers;
        longerLength = other.length;

        shorter = numbers;
        shorterLength = length;
    }

    std::string difference = "";
    int currentDifference = 0;
    int carryOver = 0;
    int x;
    int y;
    while (shorterLength > 0)
    {
        x = longer[--longerLength];
        y = shorter[--shorterLength] + carryOver;

        currentDifference = x - y;

        if (currentDifference < 0)
        {
            carryOver = 1;
            std::string numString = std::to_string(carryOver) + std::to_string(x);
            currentDifference = std::stoi(numString) - y;
        } else {
            carryOver = 0;
        }
        difference = std::to_string(currentDifference) + difference;
    }

    while (longerLength > 0)
    {
        x = longer[--longerLength];
        y = carryOver;

        currentDifference = x - y;

        if (currentDifference < 0)
        {
            carryOver = 1;
            std::string numString = std::to_string(carryOver) + std::to_string(x);
            currentDifference = std::stoi(numString) - y;
        } else {
            carryOver = 0;
        }
        difference = std::to_string(currentDifference) + difference;
    }

    bool hasPositiveSign = ((isPositive && other.isPositive) && (*this) > other) || ((*this) < other && (isPositive == false && other.isPositive));

    largeIntegers newLargeInt(difference, hasPositiveSign);
    return newLargeInt;
}


std::string largeIntegers::getNumber() const 
{
    return (isPositive ? "" : "-") + numberString;
}

bool largeIntegers::operator==(largeIntegers& other) const 
{
    return (getNumber() == other.getNumber()) && (isPositive == other.isPositive);
}

bool largeIntegers::operator>(largeIntegers& other) const 
{
    if (*this == other) return false;

    if (isPositive && other.isPositive == false) return true;

    if (length > other.length) return true;

    if ((isPositive == false && other.isPositive == false) && (length < other.length)) return true;


    if (length == other.length)
    {
        const bool bothNumbersArePositive = isPositive && other.isPositive;
        const bool bothNumbersAreNegative = (isPositive == false) && (other.isPositive == false);

        for (int i = 0; i < length; i++) {
            if (((numbers[i] > other.numbers[i]) && bothNumbersArePositive) || ((numbers[i] < other.numbers[i]) && bothNumbersAreNegative)) 
                return true;
        }
    }

    return false;
}

bool largeIntegers::operator<(largeIntegers& other) const 
{
    return (*this > other) == false;
}

largeIntegers largeIntegers::operator=(largeIntegers& other)
{
    largeIntegers newInt;

    newInt.isPositive = other.isPositive;
    newInt.numbers = other.numbers;
    newInt.length = other.length;
    newInt.numberString = other.numberString;

    return newInt;
}