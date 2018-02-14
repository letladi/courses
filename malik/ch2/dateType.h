class dateType
{
public:
    void setDate(int month, int day, int year);
    int getDay() const;
    void setDay(int);
    int getMonth() const;
    void setMonth(int);
    int getYear() const;
    void setYear(int);
    static bool isLeapYear(int);
    void print() const;
    dateType(int month = 1, int day = 1, int year = 1900);
    int numDaysInAMonth() const;
    int daysPassedDuringYear() const;
    int daysRemainingDuringYear() const;
    int totalDaysInYear() const;
    bool equals(dateType &otherDate) const;
    void addDays(int);
private:
    int dMonth;
    int dDay;
    int dYear;
    static int maxDaysForMonth[12];
    static int JAN;
    static int FEB;
    static int DECEMBER;
    static int MAX_NUM_MONTHS;
    static int numDaysInFebDuringLeapYear;
    int getMaxDaysForMonth();
    void incrementMonth();
};