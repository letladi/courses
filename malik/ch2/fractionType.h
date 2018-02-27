#include <iostream>

class fractionType {
    friend std::istream& operator>>(std::istream&, fractionType&);
    friend std::ostream& operator<<(std::ostream&, const fractionType&);
public:
    fractionType(double dividend, double divisor);
    void setDivisor(double);
    void setDividend(double);
    void getFraction(double&, double&) const;
    fractionType operator+(const fractionType&) const;
    fractionType operator-(const fractionType&) const;
    fractionType operator*(const fractionType&) const;
    fractionType operator/(const fractionType&) const;
    bool operator<(const fractionType&) const;
    bool operator>(const fractionType&) const;
    bool operator==(const fractionType&) const;
private:
    double dividend;
    double divisor;
};
