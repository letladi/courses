#include <iostream>
#include <string>
using namespace std;

string max_str(string a, string b)
{
    return a.size() > b.size() ? a : b;
}

string lcs(string a, string b, string result = "")
{
    if (a.size() == 0 || b.size() == 0) {
        return result;
    } else if (a[0] == b[0]) {
        return lcs(a.substr(1), b.substr(1), result + a[0]);
    } else {
        return max_str(lcs(a, b.substr(1), result), lcs(a.substr(1), b, result));
    }
}

int main(void)
{
    cout << lcs("faPkdmElxiyjROOhuFHbaKpmmVAXQcPTiwtCiJC", "BVObzwbRESpqhpvjiDGmlVJ") << endl;
    return 0;
}

// int main(void)
// {
//     using namespace std;

//     string main_string, small_string;
//     cout << "Enter big string: ";
//     cin >> main_string;
//     cout << "Enter small string: ";
//     cin >> small_string;
    
//     int small_str_len = small_string.size(),
//         main_str_len = main_string.size();

//     char c;

//     // we are not just looking for any subsequence,
//     // we are looking for the largest subsequence.
//     int i, j, len;
//     int main_i = 0, 
//         sj = 0,
//         largest = -1,
//         current_main_str_substring_len = main_str_len;

//     while (main_i < main_str_len) {
//         // if the current max length is greater than the substring we are 
//         // considering in the main string, then there is no need to continue
//         // if (current_main_str_substring_len < largest) break;

//         sj = 0;
//         len = 0;

//         for (i = main_i; i < main_str_len; i++) {
//             c = main_string[i];
//             for (j = sj; j < small_str_len; j++) {
//                 if (c == small_string[j]) {
//                     sj = j + 1;
//                     len++;
//                     break;
//                 }
//             }

//             if (sj >= small_str_len || sj >= main_str_len) break;
//         }

//         cout << "len = " << len << endl;

//         if (largest < len) largest = len;

//         main_i++;
//         // current_main_str_substring_len = main_str_len - main_i;
//     }

//     cout << largest << endl;

//     return 0;
// }