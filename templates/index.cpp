#include <iostream>
using namespace std;

template<typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(true?a:b)
{
   return b < a ? a : b;
}

int main()
{
   cout << "max(5.5, 6) = " << ::max(5.5, 6) << endl;
}
