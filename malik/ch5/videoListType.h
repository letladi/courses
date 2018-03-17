#include <string>
#include "unorderedLinkedList.h"
#include "videoType.h"

using namespace std;

class videoListType : public unorderedLinkedList<videoType>
{
public:
    bool videoSearch(string title) const;
    bool isVideoAvailable(string title) const;
    void videoCheckOut(string title);
    void videoCheckIn(string title);
    bool videoCheckTitle(string title) const;
    void videoUpdateInStock(string title, int num);
    void videoSetCopiesInStock(string title, int num);
    void videoPrintTitle() const;
private:
    void searchVideoList(string title, bool& found, nodeType<videoType>* &current) const;
};
