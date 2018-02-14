#include "dispenserType.h"

int dispenserType::getNoOfItems() const
{
    return numberOfItems;
}

int dispenserType::getCost() const
{
    return cost;
}

void dispenserType::makeSale()
{
    numberOfItems--;
}

dispenserType::dispenserType()
{
    numberOfItems = 50;
    cost = 50;
}

dispenserType::dispenserType(int itemCount, int itemCost)
{
    if (itemCount >= 0) { 
        numberOfItems = itemCount;
    } else {
        numberOfItems = 50;
    }

    if (itemCost >= 0) {
        cost = itemCost;
    } else {
        cost = 50;
    }
}