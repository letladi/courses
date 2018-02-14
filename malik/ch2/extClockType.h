#include "clockType.h"
#include <string>

class extClockType: public clockType
{
public:
    extClockType(int hr, int min, int sec, std::string tz);
    extClockType();
    std::string getTimeZone() const;
    void setTimeZone(std::string tz);
    void printTime() const;
private:
    std::string timezone;
};