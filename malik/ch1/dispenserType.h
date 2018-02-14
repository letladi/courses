class dispenserType
{
public:
    int getNoOfItems() const;
    int getCost() const;
    void makeSale();
    dispenserType();
    dispenserType(int itemCount, int itemCost);

private:
    int numberOfItems;
    int cost;
};