#include <iostream>
#include "orderedLinkedList.cpp"
using namespace std;

int main()
{
    orderedLinkedList<int> list1, list2;
    int num;

    cout << "Line 7: Enter numbers ending with -999: " << endl;
    cin >> num;

    while (num != -999)
    {
        list1.insert(num);
        cin >> num;
    }

    cout << endl;

    cout << "Line 15: list1: ";
    list1.print();
    cout << endl;

    list2 = list1;

    cout << "Line 27: list2: ";
    list2.print();
    cout << endl;

    cout << "Line 31: Enter the number to be deleted: ";
    cin >> num;
    cout << endl;

    list2.deleteNode(num);

    cout << "Line 37: After deleting " << num << ", list2: " << endl;
    list2.print();
    cout << endl;
}