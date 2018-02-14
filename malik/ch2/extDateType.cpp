#include "extDateType.h"
#include <iostream>

std::string extDateType::MONTH_NAMES[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

extDateType::extDateType(int day, int month, int year) : dateType(month, day, year)
{

}

std::string extDateType::getMonthName() const {
    return extDateType::MONTH_NAMES[getMonth() - 1];
}

void extDateType::printStringFormat() const {
    std::cout << getMonthName() << " " << getDay() << ", " << getYear() << std::endl;
}

void extDateType::printMonth() const {
    std::cout << getMonthName() << " " << getYear();
}