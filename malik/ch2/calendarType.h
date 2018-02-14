#include "extDateType.h"
#include "../ch1/dayType.h"
#include <string>

class calendarType
{
public:
    std::string firstDayOfMonth();
    void setMonth(int);
    void setYear(int);
    int getMonth() const;
    int getYear() const;
    void print() const;
    calendarType();
    calendarType(int day, int month, int year, std::string dayName = "Monday");

private:
    extDateType date;
    dayType day;
    static int dayDifference(int year1, int year2);
    static std::string daysOfTheWeek[7];
};