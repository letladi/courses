#include "courseType.h"

void courseType::setCourseInfo(string cName, string cNo, char grade, int credits)
{
    courseName = cName;
    courseNo = cNo;
    courseGrade = grade;
    courseCredits = credits;
}

void courseType::print(ostream& outp, bool isGrade)
{
    outp << left;
    outp << setw(8) << courseNo << " ";
    outp << setw(15) << courseName;
    outp.unsetf(ios::left);
    outp << setw(3) << courseCredits << " ";

    outp << setw(4) << (isGrade ? courseGrade : "***") << endl;
}

courseType::courseType(string cName, string cNo, char grade, int credits)
{
    setCourseInfo(cName, cNo, grade, credits);
}

int courseType::getCredits()
{
    return courseCredits;
}

char courseType::getGrade()
{
    return courseGrade;
}

void courseType::getCourseNumber(string& cNo)
{
    cNo = courseNo;
}

bool courseType::operator==(const courseType& right) const
{
    return (courseNo == right.courseNo);
}

bool courseType::operator!=(const courseType& right) const
{
    return (courseNo != right.courseNo);
}

bool courseType::operator<=(const courseType& right) const
{
    return (courseNo <= right.courseNo);
}

bool courseType::operator<(const courseType& right) const
{
    return (courseNo < right.courseNo);
}

bool courseType::operator>=(const courseType& right) const
{
    return (courseNo >= right. courseNo);
}

bool courseType::operator>(const courseType& right) const
{
    return (courseNo > right.courseNo);
}
