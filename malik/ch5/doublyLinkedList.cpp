#include "doublyLinkedList.h"
##include <iostream>

template <class Type>
doublyLinkedList<Type>::doublyLinkedList()
{
    first = NULL;
    last = NULL;
    count = 0;
}

template <class Type>
bool doublyLinkedList<Type>::isEmptyList() const
{
    return first == NULL;
}

template <class Type>
void doublyLinkedList<Type>::destroy()
{
    nodeType<Type> *temp;

    while (first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    last = NULL;
    count = 0;
}

template <class Type>
void doublyLinkedList<Type>::initializeList()
{
    destroy();
}

template <class Type>
void doublyLinkedList<Type>::print() const
{
    nodeType<Type> *current;
    current = first;
    while (current != NULL) {
        std::cout << current->info << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <class Type>
void doublyLinkedList<Type>::reversePrint() const
{
    nodeType<Type> *current;
    current = last;
    while (current != NULL) {
        std::cout << current->info << " ";
        current = current->back;
    }
    std::cout << std::endl;
}

template <class Type>
bool doublyLinkedList<Type>::search(const Type& item) const
{
    bool found = false;
    nodeType<Type> *current;

    current = first;

    while (current != NULL && !found)
        if (current->info >= item)
            found = true;
        else
            current = current->next;

    if (found)
        found = current->info == item;

    return found;
}

template <class Type>
Type doublyLinkedList<Type>::front() const
{
    assert(first != NULL);
    return first->info;
}

template <class Type>
Type doublyLinkedList<Type>::back() const
{
    assert(last != NULL);
    return last->info;
}

template <class Type>
void doublyLinkedList<Type>::insert(const Type& item)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *newNode;
    bool found;

    newNode = new nodeType<Type>;
    newNode->info = item;
    newNode->next = NULL;
    newNode->back = NULL;

    if (first == NULL) {
        first = newNode;
        last = newNode;
        count++;
    } else {
        found = false;
        current = first;

        while (current != NULL && !found)
            if (current->info >= item) found = true;
            else {
                trailCurrent = current;
                current = current->next;
            }

        if (current == first) {
            first->back = newNode;
            newNode->next = first;
            first = newNode;
            count++;
        } else {
            if (current != NULL) {
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                newNode->next = current;
                current->back = newNode;
            } else {
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                last = newNode;
            }
            count++;
        }
    }
}


template <class Type>
void doublyLinkedList<Type>::deleteNode(const Type& item)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;

    bool found;

    if (first == NULL) std::cout << "Cannot delete from an empty list." << std::endl;
    else if (first->info == item)
    {
        current = first;
        first = first->next;
        if (first != NULL) first->back = NULL;
        else last = NULL;

        count--;
        delete current;
    }
    else
    {
        found = false;
        current = first;

        while (current != NULL && !found)
            if (current->info >= item) found = true;
            else current = current->next;

        if (current == NULL) std::cout << "The item to be deleted is not in the list." << std::endl;
        else if (current->info == item)
        {
            trailCurrent = current->back;
            trailCurrent->next = current->next;

            if (current->next != NULL)
                current->next->back = trailCurrent;

            if (current == last) last = trailCurrent;

            count--;
            delete current;
        } else std::cout << "The item to be deleted is not in the list." << std::endl;
    }
}
