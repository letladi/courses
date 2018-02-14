#include "dateType.h"
#include <string>

class extDateType : public dateType
{
public:
    void printStringFormat() const;
    std::string getMonthName() const;
    void printMonth() const;
    extDateType(int day, int month, int year);
private:
    static std::string MONTH_NAMES[12];
};