#include "clockType.h"
#include <iostream>
void clockType::setTime(int hrs, int mins, int secs) {
    if (0 <= hrs && hrs < 24) {
        hr = hrs;
    } else {
        hr = 0;
    }

    if (0 <= mins && mins < 60) {
        min = mins;
    } else {
        min = 0;
    }

    if (0 <= secs && secs < 60) {
        sec = secs;
    } else {
        sec = secs;
    }
}

void clockType::getTime(int &hrs, int &mins, int &secs) const {
    hrs = hr;
    mins = min;
    secs = sec;
}

void clockType::printTime() const {
    if (hr < 10) {
        std::cout << "0";
    }
    std::cout << hr << ":";

    if (min < 10) {
        std::cout << "0";
    }
    std::cout << min << ":";

    if (sec < 10) {
        std::cout << "0";
    }
    std::cout << sec;
}

void clockType::incrementHours() {
    hr++;
    if (hr > 23)
        hr = 0;
}

void clockType::incrementMinutes() {
    min++;
    if (min > 59) {
        min = 0;
        incrementHours();
    }
}

void clockType::incrementSeconds() {
    sec++;
    if (sec > 59) {
        sec = 0;
        incrementMinutes();
    }
}

bool clockType::equalTime(const clockType &otherClock) const {
    return (hr == otherClock.hr
        && min == otherClock.min
        && sec == otherClock.sec);
}

clockType::clockType(int hrs, int mins, int secs) {
    setTime(hrs, mins, secs);
}