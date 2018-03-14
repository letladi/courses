#include <string>
using namespace std;

class courseType
{
public:
    void setCourseInfo(string cName, string cNo, char grade, int credits);
    void print(ostream& outp, bool isGrade);
    int getCredits();
    void getCourseNumber(string& cNo);
    char getGrade();
    bool operator==(const courseType&) const;
    bool operator!=(const courseType&) const;
    bool operator<=(const courseType&) const;
    bool operator<(const courseType&) const;
    bool operator>=(const courseType&) const;
    bool operator>(const courseType&) const;
    courseType(string cName = "", string cNo = "", char grade = '*', int credits = 0);
private:
    string courseName;
    string courseNo;
    char courseGrade;
    int courseCredits;
};
