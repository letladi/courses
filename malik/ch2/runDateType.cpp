#include "../test.cpp"
#include "dateType.h"

int main() {
    suite("Testing dateType class");
    suite("#isLeapYear");

    int falseLeapYears[] = { 1700, 1800, 1900, 2100, 2200, 2300, 2500, 2600 };
    for (auto& year : falseLeapYears) {
        assertEqual(false, dateType::isLeapYear(year), std::to_string(year) + " is not a leap year");
    }

    int trueLeapYears[] = { 1600, 2000, 2400 };
    for (auto& year : trueLeapYears) {
        assertEqual(true, dateType::isLeapYear(year), std::to_string(year) + " is not a leap year");
    }

    dateType date1(3, 21, 2011);
    suite("#numDaysInAMonth");
    assertEqual(31, date1.numDaysInAMonth(), "March should have 31 days");

    dateType date2(3, 18, 2011);
    suite("#daysPassedDuringYear");
    assertEqual(77, date2.daysPassedDuringYear(), "77 days have passed if date is 3-18-2011");

    dateType date3(3, 18, 2011);
    suite("#daysRemainingDuringYear");
    assertEqual(288, date3.daysRemainingDuringYear(), "288 days are remaining if date is 3-18-20111");

    suite("#equals");
    assertEqual(true, date3.equals(date2), "equals dates are equal 3-18-2011=3-18-2011");
    assertEqual(false, date3.equals(date1), "different dates are not equal 3-18-2011 != 3-21-2011");

    suite("#addDays");
    dateType date4(3, 18, 2011);
    date4.addDays(25);
    dateType date5(4, 12, 2011);
    assertEqual(true, date4.equals(date5), "adding 25 days to 3-18-2011 produces 4-12-2011");
    std::cout << "here is the after date: ";
    date4.print();
    std::cout << std::endl;

    dateType date6(12, 12, 2011);
    dateType date7(1, 11, 2012);
    date6.addDays(30);
    assertEqual(true, date7.equals(date6), "adding 30 days to 12-12-2011 produces 1-11-2012");
    std::cout << "here is the after date ";
    date6.print();
    std::cout << std::endl;
}