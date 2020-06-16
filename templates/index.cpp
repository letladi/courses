#include <iostream>
#include <array>
using namespace std;

template <char... cs>
void operator"" _B7()
{
   std::array<char, sizeof...(cs)> chars{cs...};
   for (char c : chars) {
      cout << "'" << c << "'";
   }
   cout << endl;
}

int main()
{
   01.3_B7;
   0xFF00_B7;
   // auto d = 0815_B7;


   return 0;
}
