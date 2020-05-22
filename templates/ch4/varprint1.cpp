#include <iostream>

void print()
{

}

template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
   std::cout << firstArg << '\n'; // print first arg
   print(args...); // call print for remaining args
}

int main()
{
   std::string s("world");
   print(7.5, "hello", s);
}
