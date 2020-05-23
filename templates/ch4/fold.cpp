#include <iostream>

template <typename... T>
auto foldSum(T... s)
{
   return (... + s);
}

int main()
{
   std::cout << "foldSum(20, 5, 10, 55, 60) = " << foldSum(20, 5, 10, 55, 60) << std::endl;

   return 0;
}
