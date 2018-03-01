#include "romanType.h"

class extRomanType : public romanType
{
public:
    extRomanType(std::string);
    extRomanType(int);
    extRomanType operator+(const extRomanType& other) const;
    extRomanType operator-(const extRomanType& other) const;
    extRomanType operator*(const extRomanType& other) const;
    extRomanType operator/(const extRomanType& other) const;
    extRomanType& operator++();
    extRomanType operator++(int);
    extRomanType& operator--();
    extRomanType operator--(int);
};
