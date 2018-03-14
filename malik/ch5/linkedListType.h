#include "linkedListIterator.h"

template <class Type>
class linkedListType
{
public:
    const linkedListType<Type>& operator=(const linkedListType<Type>&);
    void initializeList();
    bool isEmptyList() const;
    void print() const;
    int length() const;
    void destroyList() const;
    Type front() const;
    Type back() const;
    virtual bool search(const Type& searchItem) const = 0;
    virtual void insertFirst(const Type& newItem) = 0;
    virtual void insertLast(const Type& newItem) = 0;
    virtual void deleteNode(const Type& deleteItem) = 0;
    linkedListIterator<Type> begin();
    linkedListIterator<Type> end();
    linkedListType();
    linkedListType(const linkedListType<Type>& other);
    ~linkedListType();
protected:
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last;
private:
    void copyList(const linkedListType<Type>& other);
};
