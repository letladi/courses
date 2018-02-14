#include "extClockType.h"
#include <iostream>

extClockType::extClockType(int hr, int min, int sec, std::string tz) : clockType(hr, min, sec) {
    setTimeZone(tz);
}

extClockType::extClockType() {
    setTimeZone("SAST");
}

void extClockType::setTimeZone(std::string tz) {
    timezone = tz;
}

std::string extClockType::getTimeZone() const {
    return timezone;
}

void extClockType::printTime() const {
    clockType::printTime();
    std::cout << " (" << timezone << ")";
}