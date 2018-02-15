#include "clockType.h"

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

std::istream& operator>>(std::istream& is, clockType& clock) {
    is >> clock.hr >> clock.min >> clock.sec;
    return is;
}

std::ostream& operator<<(std::ostream& os, const clockType& clock) {
    if (clock.hr < 10) {
        os << "0";
    }
    os << clock.hr << ":";

    if (clock.min < 10) {
        os << "0";
    }
    os << clock.min << ":";

    if (clock.sec < 10) {
        os << "0";
    }
    os << clock.sec;
    os << std::endl;

    return os;
}

clockType& clockType::operator++() {
    ++sec;
    return *this;
}

clockType& clockType::operator++(int) {
    sec++;
    return *this;
}

bool clockType::operator<(clockType &clock) const {
    if (*this == clock) return false;

    if (hr < clock.hr) {
        return true;
    }  else {
        if (min < clock.hr) {
            return true;
        } else {
            if (sec < clock.hr) {
                return true;
            }
        }
    }
    return false;
}

bool clockType::operator<=(clockType &clock) const {
    return (*this == clock) || (hr <= clock.hr);
}

bool clockType::operator==(clockType &clock) const {
    return (hr == clock.hr && min == clock.min && sec == clock.sec);
}

bool clockType::operator>(clockType &clock) const {
    if (*this == clock) return false;

    if (hr > clock.hr) {
        return true;
    }  else {
        if (min > clock.hr) {
            return true;
        } else {
            if (sec > clock.hr) {
                return true;
            }
        }
    }
    return false;
}

bool clockType::operator>=(clockType &clock) const {
    return (*this == clock) ||  (hr >= clock.hr);
}