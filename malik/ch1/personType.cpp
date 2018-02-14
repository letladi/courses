#include "personType.h"
#include <iostream>

void personType::print() const
{
    std::cout << firstName << " " << lastName << std::endl;
}

void personType::setName(std::string first, std::string last)
{
    firstName = first;
    lastName = last;
}

void personType::setFirstName(std::string newFirstName)
{
    firstName = newFirstName;
}

void personType::setMiddleName(std::string newMiddleName) 
{
    middleName = newMiddleName;
}

void personType::setLastName(std::string newLastName)
{
    lastName = newLastName;
}

std::string personType::getFirstName() const
{
    return firstName;
}

std::string personType::getLastName() const 
{
    return lastName;
}

bool personType::isSimilarFirstName(std::string otherFirstName) const
{
    return firstName.compare(otherFirstName) == 0;
}

bool personType::isSimilarLastName(std::string otherLastName) const
{
    return lastName.compare(otherLastName) == 0;
}

personType::personType()
{
    firstName = "";
    lastName = "";
}

personType::personType(std::string first, std::string last)
{
    firstName = first;
    lastName = last;
}