#include <iostream>

template <auto T>
class Message
{
public:
   void print() {
      std::cout << T << '\n';
   }
};

int main()
{
   Message<42> msg1;
   msg1.print();

   static char const s[] = "hello";
   Message<s> msg2;
   msg2.print();
}
