#include <iostream>
#include <string>
#include <array>

class largeIntegers
{
    friend std::istream& operator>>(std::istream&, largeIntegers&);
    friend std::ostream& operator<<(std::ostream&, largeIntegers&);
public:
    largeIntegers();
    largeIntegers(std::string);
    largeIntegers operator-(largeIntegers&) const;
    largeIntegers operator+(largeIntegers&) const;
    std::string getNumber() const;
private:
    std::string numberString;
    int length;
    std::array<int, 100> numbers;
    void setNumbers(std::string);
    int intVal(char&) const;
};