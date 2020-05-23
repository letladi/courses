#include <iostream>

template <typename T>
void print(T arg)
{
   std::cout << arg << '\n';
}

template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
   print(firstArg);
   std::cout << "[left with " << sizeof...(args) << " args]\n";
   print(args...);
}

int main()
{
   print(2.8, "hello", "world");
}
