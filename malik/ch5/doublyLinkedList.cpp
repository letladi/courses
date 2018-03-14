#include "doublyLinkedList.h"

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