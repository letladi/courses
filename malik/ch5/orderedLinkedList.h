#ifndef H_orderedListType
#define H_orderedListType
#include "linkedListType.cpp"

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& item) const;
    void insert(const Type& item);
    void insertFirst(const Type& item);
    void insertLast(const Type& item);
    void deleteNode(const Type& item);
};

#endif