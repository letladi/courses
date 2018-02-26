#include <iostream>
#include <string>
#include <array>

class largeIntegers
{
    friend std::istream& operator>>(std::istream&, largeIntegers&);
    friend std::ostream& operator<<(std::ostream&, largeIntegers&);
public:
    largeIntegers();
    largeIntegers(std::string, bool = true);
    largeIntegers operator-(largeIntegers&) const;
    largeIntegers operator+(largeIntegers&) const;
    bool operator==(largeIntegers&) const;
    bool operator>(largeIntegers&) const;
    bool operator<(largeIntegers&) const;
    void setNumbers(std::string);
    std::string getNumber() const;
private:
    std::string numberString;
    int length;
    bool isPositive;
    std::array<int, 100> numbers;
    int intVal(char&) const;
};