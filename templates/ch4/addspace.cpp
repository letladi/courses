#include <iostream>

template <typename T>
class AddSpace
{
private:
   T const& ref; // refers to argument passed in constructor
public:
   AddSpace(T const& r) : ref(r) {}
   friend std::ostream& operator<<(std::ostream& os, AddSpace<T> s) {
      return os << s.ref << ' '; // output passed argument and space
   }
};

template <typename... Args>
void print(Args... args)
{
   (std::cout << ... << AddSpace(args)) << '\n';
}
