#include "dateType.h"
#include <iostream>

int dateType::maxDaysForMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int dateType::MAX_NUM_MONTHS = 12;
int dateType::numDaysInFebDuringLeapYear = 29;
int dateType::JAN = 1;
int dateType::FEB = 2;
int dateType::DECEMBER = 12;

int dateType::getDay() const {
    return dDay;
}

void dateType::setDay(int newDay) {
    const int index = getMonth() - 1;
    const int maxDaysForThisMonth = dateType::maxDaysForMonth[index];

    if (1 <= newDay && newDay <= maxDaysForThisMonth) {
        dDay = (getMonth() == FEB && isLeapYear(getYear()))
               ? numDaysInFebDuringLeapYear
               : newDay;
    } else {
        dDay = 1;
    }
}

int dateType::getMonth() const {
    return dMonth;
}

void dateType::setMonth(int newMonth) {
    if (dateType::JAN <= newMonth && newMonth <= dateType::DECEMBER) {
        dMonth = newMonth;
    } else {
        dMonth = 1;
    }
}

int dateType::getYear() const {
    return dYear;
}

void dateType::setYear(int newYear) {
    if (newYear >= 1) {
        dYear = newYear;
    } else {
        dYear = 1900;
    }
}

void dateType::print() const {
    std::cout << dMonth << "-" << dDay << "-" << dYear;
}

dateType::dateType(int month, int day, int year) {
    setDate(month, day, year);
}

void dateType::setDate(int month, int day, int year) {
    setMonth(month);
    setDay(day);
    setYear(year);
}

bool dateType::isLeapYear(int year) {
    return year % 100 == 0 && year % 400 == 0;
}

int dateType::numDaysInAMonth() const {
    const int index = getMonth() - 1;

    return (isLeapYear(getYear()) && getMonth() == FEB) ? 29 : dateType::maxDaysForMonth[index];
}

int dateType::daysPassedDuringYear() const {
    int totalDays = 0;
    for (int i = 0, maxIteration = getMonth() - 1; i < maxIteration; i++) {
        totalDays += dateType::maxDaysForMonth[i];
    }

    totalDays += getDay();

    if (isLeapYear(getYear())) {
        totalDays++;
    }
    return totalDays;
}

int dateType::totalDaysInYear() const {
    return isLeapYear(getYear()) ? 366 : 365;
}

int dateType::daysRemainingDuringYear() const {
    return totalDaysInYear() - daysPassedDuringYear();
}

bool dateType::equals(dateType &otherDate) const {
    return dMonth == otherDate.dMonth && dDay == otherDate.dDay && dYear == otherDate.dYear;
}

int dateType::getMaxDaysForMonth() {
    const int month = getMonth();
    return (isLeapYear(getYear()) && month == dateType::FEB) ? 29 : dateType::maxDaysForMonth[month - 1];
}

void dateType::incrementMonth() {
    if (getMonth() == dateType::DECEMBER) {
        setYear(getYear() + 1);
        setMonth(1);
    } else {
        setMonth(getMonth() + 1);
    }

}

void dateType::addDays(int days) {
    while (days > 0) {
        if (getDay() + days > getMaxDaysForMonth()) {
            const int daysToBeSubtractedFromTotalAddition = getMaxDaysForMonth() - getDay() + 1;
            days -= daysToBeSubtractedFromTotalAddition;
            incrementMonth();
            setDay(1);
        } else {
            setDay(getDay() + days);
            break;
        }
    }
}