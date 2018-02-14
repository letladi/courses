#include "dayType.h"
#include <iostream>

int main() {
    dayType dayT;
    dayT.print();
    std::cout << "Here is the next day: " << dayT.getNextDay() << std::endl;
    std::cout << "here is the previous day: " << dayT.getPreviousDay() << std::endl;

    dayT.setDay("Tuesday");
    std::cout << "Here is day after setting: " << dayT.getDay() << std::endl;
}