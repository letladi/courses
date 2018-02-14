#include <string>

class personType 
{
public:
	void print() const;
	void setName(std::string first, std::string last);
	std::string getFirstName() const;
	std::string getLastName() const;
	personType();
	personType(std::string first, std::string last);

private:
	std::string firstName;
	std::string lastName;
};