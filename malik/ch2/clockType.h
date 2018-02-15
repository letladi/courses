#include <iostream>

class clockType
{
public:
  void setTime(int hrs, int mins, int secs);
    void getTime(int& hrs, int& mins, int& secs) const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType& otherClock) const;
    friend std::istream& operator>>(std::istream& is, clockType& clock);
    friend std::ostream& operator<<(std::ostream& os, const clockType& clock);
    clockType& operator++();
    clockType& operator++(int);
    bool operator>(clockType& clock) const;
    bool operator>=(clockType& clock) const;
    bool operator<(clockType& clock) const;
    bool operator<=(clockType& clock) const;
    bool operator==(clockType& clock) const;

    clockType(int hrs = 0, int mins = 0, int secs = 0);
private:
    int hr;
    int min;
    int sec;
};