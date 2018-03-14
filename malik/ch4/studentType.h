class studentType: public personType
{
public:
    void setInfo(string fname, string lName, int ID, bool isTPaid, vector<courseType> courses);
    void print(ostream& out, double tuitionRate);
    studentType();
    int getHoursEnrolled();
    double getGpa();
    double billingAmount(double tuitionRate);
private:
    int sId;
    int numberOfCourses;
    bool isTuitionPaid;
    vector<courseType> coursesEnrolled;
};
