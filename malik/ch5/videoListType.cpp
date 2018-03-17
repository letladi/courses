#include "videoListType.h"

void videoListType::searchVideoList(string title, bool& found, nodeType<videoType>* &current) const
{
    found = false;
    current = first;
    while (current != NULL && !found) {
        if (current->info.checkTitle(title)) found = true;
        else current = current->link;
    }
}

bool videoListType::isVideoAvailable(string title) const
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);

    if (found) found = (location->info.getNoOfCopiesInStock() > 0);
    else found = false;
    return found;
}

void videoListType::videoCheckIn(string title)
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    if (found) location->info.checkIn();
    else cout << "The store does not not carry " << title << endl;
}

void videoListType::videoCheckOut(string title)
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    if (found) location->info.checkOut();
    else cout << "The store does not carry " << title << endl;
}

bool videoListType::videoCheckTitle(string title) const
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    return found;
}

void videoListType::videoUpdateInStock(string title, int num)
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    if (found) location->info.updateInStock(num);
    else cout << "The store does not carry " << title << endl;
}

void videoListType::videoSetCopiesInStock(string title, int num)
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    if (found) location->info.setCopiesInStock(num);
    else cout << "The store does not carry " << title << endl;
}

bool videoListType::videoSearch(string title) const
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    return found;
}

void videoListType::videoPrintTitle() const
{
    nodeType<videoType> *current;
    current = first;
    while (current != NULL)
    {
        current->info.printTitle();
        current = current->link;
    }
}
