#include <string>

class personType
{
public:
    void print() const;
    void setName(std::string, std::string);
    void setFirstName(std::string);
    void setMiddleName(std::string);
    void setLastName(std::string);
    std::string getFirstName() const;
    std::string getLastName() const;
    bool isSimilarFirstName(std::string) const;
    bool isSimilarLastName(std::string) const;
    personType();
    personType(std::string, std::string);
private:
    std::string firstName;
    std::string middleName;
    std::string lastName;
};