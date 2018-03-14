#include "linkedListType.h"
#include <iostream>

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return first == NULL;
}

template <class Type>
linkedListType<Type>::linkedListType()
{
    first = NULL;
    last = NULL;
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;

    while (first != NULL)
    {
        temp = first;
        first = first->link;
        delete temp;
    }

    last = NULL;
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList();
}

template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current;
    current = first;

    while (current != NULL)
    {
        std::cout << current->info << " ";
        current = current->link;
    }
}

template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}

template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != NULL);
    return first->info;
}

template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != NULL);
    return last->info;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);
    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);
    return temp;
}


template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& other)
{
    nodeType<Type> *newNode;
    nodeType<Type> *current;

    if (first != NULL) destroyList();

    if (other.first == NULL)
    {
        first = NULL;
        last = NULL;
        count = 0;
    } else {
        current = other.first;
        count = other.count;

        first = new NodeType<Type>;
        first->info = current->info;
        first->link = NULL;
        last = first;
        current = current->link;

        while (current != NULL)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;

            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
    destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& other)
{
    first = NULL;
    copyList(other);
}

template <class Type>
onst linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& other)
{
    if (this != &other) copyList(other);
    return
}
