#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> list;

    list.push_back(13);
    list.push_back(75);
    list.push_back(28);
    list.push_back(35);

    cout << "Line 11: List Elements: ";
    for (int i = 0; i < 4; i++) cout << list[i] << " ";
    cout << endl;

    for (int i = 0; i < 4; i++) list[i] *= 2;
}