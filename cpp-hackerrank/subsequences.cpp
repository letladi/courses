#include <iostream>

int main(void)
{
    using namespace std;

    string main_string, small_string;
    cout << "Enter big string: ";
    cin >> main_string;
    cout << "Enter small string: ";
    cin >> small_string;

    int sj = 0, len = 0, j, largest = -1;
    
    int small_str_len = small_string.size(),
        main_str_len = main_string.size();
    int si = 0, i;
    char c;

    // we are not just looking for any subsequence,
    // we are looking for the largest subsequence.
    for (i = si; i < main_str_len; si++) {
        c = main_string[i];
        for (j = sj; i < small_str_len; j++) {
            if (c == small_string[j]) {
                sj = j + 1;
                len++;
                break;
            }
        }

        if (sj >= small_str_len) break;
    }

    cout << len << endl;

    return 0;
}