#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    list<int> intList1, intList2;

    ostream_iterator<int> screen(cout, " ");

    int nums[] = { 23, 58, 58, 36, 15, 98, 58 };
    for (int& i : nums) intList1.push_back(i);

    cout << "Line 17: intList1: ";
    copy(intList1.begin(), intList1.end(), screen);
    cout << endl;

    intList2 = intList1;

    cout << "Line 23: intList2: ";
    copy(intList2.begin(), intList2.end(), screen);
    cout << endl;

    intList1.unique();

    cout << "Line 29: After removing the consecutive duplicates, " << endl << "       intList1: ";
    copy(intList1.begin(), intList1.end(), screen);
    cout << endl;

    intList2.sort();

    cout << "Line 35: After sorting, intList2: ";
    copy(intList2.begin(), intList2.end(), screen);
    cout << endl;

}
