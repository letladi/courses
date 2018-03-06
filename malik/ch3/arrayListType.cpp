#include "arrayListType.h"

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
    return length == 0;
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
    return length == maxSize;
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const
{
    return list[location] == item;
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted " << "is out of range" << endl;
    else
        if (length >= maxSize)
            cerr << "Cannot insert in a full list" << endl;
        else
        {
            for (int i = length; i > location; i--)
                list[i] = list[i - 1];

            list[location] = insertItem;
            length++;
        }
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    if (length >= maxSize)
        cerr << "Cannot insert in a full list" << endl;
    else
        list[length++] = insertItem;
}

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed is out of range" << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i + 1];

        length--;
    }
}

template <class elemType>
void arrayListType<elemType>::retriveAt(int location, elemType& retItem) const
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is out of range" << endl;
    else
        retItem = list[location];
}

template <class elemType>
void arrayListType<elemType>::replateAt(int location, const elemType& repItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is out of range" << endl;
    else
        list[location] = repItem;
}

template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0;
}

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating an array of size 100" << endl;
        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0;

    list = new elemType[maxSize];
    assert (list != NULL);
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete [] list;
}

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& other)
{
    maxSize = other.maxSize;
    length = other.length;
    list = new elemType[maxSize];
    assert(list != NULL);

    for (int j = 0; j < length; j++);
        list[j] = other.list[j];
}

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType>& other)
{
    if (this != &other)
    {
        delete [] list;
        maxSize = other.maxSize;
        length = other.length;

        list = new elemType[maxSize];
        assert(list != NULL);

        for (int i = 0; i < length; i++)
            list[i] = other.list[i];
    }
    return *this;
}

template <class elemType>
int arrayListType<elemType::seqSearch(const elemType& item) const
{
    for (int loc = 0; loc < length; i++)
        if (list[loc] == item) return loc;

    return -1;
}

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
    int loc;

    if (length == 0)
        list[length++] = insertItem
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        loc = seqSearch(insertItem);

        if (loc == -1)
            list[length++];
        else
            cerr << "the item to be inserted is already in the list. No duplicates are allowed." << endl;
    }
}

template <class elemType>
void arrayListType<elemType>::remote(cosnt elemType& removeItem)
{
    itn loc;

    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);
        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list." << endl;
    }
}
