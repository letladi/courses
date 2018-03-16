#include <iostream>
#include <string>

using namespace std;

class videoType
{
    friend ostream& operator<<(ostream&, const videoType&);
public:
    void setVideoInfo(string title, string start1, string star2, string producer,
        strind director, string productionCo, int setInStock);
    int getNoOfCopiesInStock() const;
    void checkOut();
    void checkIn();
    void printTitle() const;
    void printInfo() const;
    bool checkTitle(string title);
    void updateInStock(int num);
    void setCopiesInStock(int num);
    string getTitle() const;
    videoType(string title = "", string star1 = "", string star2 = "",
        string producer = "", string director = "", string productionCo = "",
        int setInStock = 0);
    bool operator==(const videoType&) const;
    bool operator!=(const videoType&) const;
private:
    string videoTitle;
    string movieStart1;
    string movieStart2;
    string movieProducer;
    string movieDirector;
    string movieProductionCo;
    int copiesInStock;
};
