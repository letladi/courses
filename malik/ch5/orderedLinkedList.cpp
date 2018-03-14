#include "orderedLinkedList.h"
#include "nodeType.cpp"
#include <iostream>

template <class Type>
bool orderedLinkedList<Type>::search(const Type& item) const
{
    bool found = false;
    nodeType<Type> *current;

    current = this->first;

    while (current != NULL && !found) {
        if (current->info >= item) found = true;
        current = current->link;
    }
    return (found) ? (current->info == item) : found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& item)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *newNode;

    bool found;

    newNode = new nodeType<Type>;
    newNode->info = item;
    newNode->link = NULL;

    if (this->first == NULL)
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    } else {
        current = this->first;
        found = false;

        while (current != NULL && !found)
        {
            if (current->info >= item) found = true;
            else {
                trailCurrent = current;
                current = current->link;
            }
        }

        if (current == this->first)
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        } else
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == NULL) this->last = newNode;
            this->count++;
        }
    }
}

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& item)
{
    insert(item);
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& item)
{
    insert(item);
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type &item)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;

    if (this->first == NULL) std::cout << "Cannot delete from an empty list." << std::endl;
    else
    {
        current = this->first;
        found = false;

        while (current != NULL && !found)
            if (current->info >= item) found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == NULL) std::cout << "The item to be deleted is not in the list." << std::endl;
        else if (current->info == item)
        {
            if (this->first == current)
            {
                this->first = this->first->link;
                if (this->first == NULL) this->last = NULL;
                delete current;
            } else
            {
                trailCurrent->link = current->link;

                if (current == this->last) this->last = trailCurrent;
                delete current;
            }
            this->count--;
        } else std::cout << "The item to be deleted is not in the list." << std::endl;
    }
}
