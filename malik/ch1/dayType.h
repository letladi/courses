#include <string>

class dayType
{
public:
    void setDay(std::string);
    void print() const;
    std::string getDay() const;
    std::string getNextDay();
    std::string getPreviousDay() const;
    int addDays(int);
    dayType();
    dayType(std::string);
    std::string getDayNameFromDayNumber(int) const;
    int getDayNumber() const;
private:
    std::string day;
    int dayNum;
};