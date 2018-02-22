#include <string>

class romanType 
{
public:
    romanType(std::string);
    romanType();
    void convertToDecimal();
    int getDecimalNum();
    std::string getRomanNum() const;
    void setRomanNum(std::string);

private:
    std::string romanNum;
    int decimalNum;
    int getDecimalForSymbol(char& c) const;
};