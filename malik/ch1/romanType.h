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

protected:
    std::string romanNum;
    int decimalNum;
private:
    int getDecimalForSymbol(char& c) const;
};
