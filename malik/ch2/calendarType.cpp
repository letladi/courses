#include "calendarType.h"
#include <iostream>

calendarType::calendarType(int day, int month, int year, std::string dayName) : date(day, month, year), day(dayName) {}

std::string calendarType::firstDayOfMonth() {
//    int daysSince1500 = dayDifference(1970, date.getYear()) + date.daysPassedDuringYear() - 1;
//    int firstDayNumber = day.addDays(daysSince1500);
//    return day.getDayNameFromDayNumber(firstDayNumber);
    extDateType tempDate(1, 1, 1500);
    while (date.equals(tempDate) == false) {
        day.setDay(day.getNextDay());
        tempDate.addDays(1);
    }
    return day.getDay();
}

int calendarType::dayDifference(int year1, int year2) {
//    if (year1 == year2) return 0;
//    int min = (year1 < year2) ? year1 : year2;
//    int max = (year1 < year2) ? year2 : year1;
//
//    int difference = 0;
//
//    while (min < max) {
//        difference += extDateType::isLeapYear(min) ? 366 : 365;
//        min++;
//    }
//    return difference
    return 1;
}

void calendarType::setYear(int year) {
    date.setYear(year);

}

int calendarType::getYear() const {
    return date.getYear();
}

int calendarType::getMonth() const {
    return date.getMonth();
}

void calendarType::setMonth(int month) {
    date.setMonth(month);
}

void calendarType::print() const {
    std::cout << "\t\t\t" << date.getMonthName() << " " << date.getYear() << std::endl;
    for (auto &weekDay: daysOfTheWeek) std::cout << weekDay << "\t";
    std::cout << std::endl;
    const int numDays = date.numDaysInAMonth();

    int startDate = day.getDayNumber();

    for (int i = startDate - 7, printCount = 0; i <= numDays; i++) {
        if (i <= 0) {
            std::cout << " ";
        } else {
            std::cout << i;
        }
        std::cout << "\t";

        printCount++;
        if (printCount % 7 == 0) std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::string calendarType::daysOfTheWeek[7]= { "Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat" };