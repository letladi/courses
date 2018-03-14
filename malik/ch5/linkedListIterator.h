#include "nodeType.cpp"
template <class Type>
class linkedListIterator
{
public:
    linkedListIterator();
    linkedListIterator(nodeType<Type> *ptr);
    Type operator*();
    linkedListIterator<Type> operator++();
    bool operator==(const linkedListIterator<Type>&) const;
    bool operator!=(const linkedListIterator<Type>&) const;

private:
    nodeType<Type> *current;
};
