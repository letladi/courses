#include <string>

class secretType {
private:
	std::string name;
	int age;
	int weight;
	double height;

public:
	void print() const;
	void setName(std::string newName);
	void setAge(std::string);
	void setWeight(std::string);
	void setHeight(std::string);
	std::string getName() const;
	int getAge() const;
	int getWeight() const;
	double getHeight() const;

	secretType();
	secretType(std::string, int, int, double);
};