#include "dayType.h"
#include <iostream>

dayType::dayType() 
{
    setDay("Monday");
}

dayType::dayType(std::string initDay)
{
    setDay(initDay);
}

void dayType::setDay(std::string newDay)
{
    day = newDay;
    dayNum = getDayNumber();

    if (dayNum < 0) {
        dayNum = 0;
        day = getDayNameFromDayNumber(dayNum);
    }
}

int dayType::getDayNumber() const
{
    std::string days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    
    int count = 0;
    for (std::string& currDay: days) {
        if (currDay.compare(day) == 0) {
            return count;
        }
        count++;
    }
    return -1;
}

std::string dayType::getDay() const 
{
    return day;
}

std::string dayType::getNextDay() 
{
    int currDayNum = getDayNumber();
    int nextDayNum = (currDayNum + 1) % 7;
    return getDayNameFromDayNumber(nextDayNum);
}

std::string dayType::getPreviousDay() const
{
    int currDayNum = getDayNumber();
    int prevDayNum = (7 + currDayNum - 1) % 7;
    return getDayNameFromDayNumber(prevDayNum);
}

int dayType::addDays(int days)
{
    int currDayNum = getDayNumber();
    return (days + currDayNum) % 7;
}

std::string dayType::getDayNameFromDayNumber(int dayNum) const
{
    switch(dayNum) {
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
        case 0: 
        default:
            return "Sunday";
    }
}

void dayType::print() const 
{
    std::cout << "Here is the current day: " << day << std::endl;
}