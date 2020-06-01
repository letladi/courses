#include <iostream>
#include <vector>
#include "len1.hpp"

int main()
{
   using namespace std;
   int a[10];
   std::cout << len(a) << endl;
   std::cout << len("tmp") << endl;
   std::vector<int> v{2};
   std::cout << len(v) << endl;;
}
