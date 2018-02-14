class clockType 
{
public:
  void setTime(int hrs, int mins, int secs);
    void getTime(int& hrs, int& mins, int& secs) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType& otherClock) const;

    clockType(int hrs = 0, int mins = 0, int secs = 0);
private:
    int hr;
    int min;
    int sec;
};