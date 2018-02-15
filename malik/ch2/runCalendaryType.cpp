#include "calendarType.h"
#include "../test.cpp"

int main() {
    suite("calendarType");
    suite("#firstDayOfMonth");

    calendarType cal1(15, 2, 2018);
    assertEqual("Thursday", cal1.firstDayOfMonth(), "the first day of Feb-2018 is Thursday");
}