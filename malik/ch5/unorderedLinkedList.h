#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedListType.h"
using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& item) const;
    void insertFirst(const Type& item);
    void insertLast(const Type& item);
    void deleteNode(const Type& item);
};

#include "unorderedLinkedList.h"

template <class Type>
bool unorderedLinkedList<Type>::search(const Type &item) const
{
    nodeType<Type> *current;

    current = first;

    while (current != NULL)
    {
        if (current->info == item) return true;
        current = current->link;
    }
    return false;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type &item)
{
    nodeType<Type> *newNode;

    newNode = new nodeType<Type>;
    newNode->info = item;
    newNode->link = first;
    first = newNode;
    count++;

    if (last == NULL) last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type &item)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = item;
    newNode->link = NULL;

    if (first == NULL)
    {
        first = newNode;
        last = newNode;
    } else {
        last->link = newNode;
        last = newNode;
    }
    count++;
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type &item)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;

    if (first == NULL) {
        std::cout << "Cannot delete from an empty list." << std::endl;
        return;
    }

    if (first->info == item) {
        current = first;
        first = first->link;
        count--;

        if (first == NULL) last = NULL;

        delete current;
    } else {
        found = false;
        trailCurrent = first;
        current = first->link;

        while (current != NULL && !found) {
            if (current->info != item) {
                trailCurrent = current;
                current = current->link;
            } else {
                found = true;
            }
        }

        if (found) {
            trailCurrent->link = current->link;
            count--;

            if (last == current)
                last = trailCurrent;
            delete current;
        } else {
            std::cout << "The item to be deleted is not in the list." << std::endl;
        }
    }
}

#endif