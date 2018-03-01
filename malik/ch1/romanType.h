#include <string>
#include <iostream>

class romanType
{
    friend std::ostream& operator<<(std::ostream&, romanType&);
    friend std::istream& operator>>(std::istream&, romanType&);
public:
    romanType(std::string = "");
    romanType(int);
    int romanToDecimal() const;
    std::string decimalToRoman() const;
    std::string getRomanNum() const;
    void setRomanNum(const std::string);
    void setDecimalNum(const int);
    int getDecimalNum() const;
protected:
    std::string romanNum;
    int decimalNum;
private:
    int getDecimalForSymbol(const char& c) const;
    std::string getSymbolForDecimal(const int n) const; 
};
