#include <iostream>
#include <iterator>

template <typename T>
void insertion_sort(T list[], size_t len)
{
   int i, j;
   for (i = 1; i < len; i++) {
      j = i;
      while ((j > 0) && (list[j] < list[j - 1])) {
         std::swap(list[j], list[j - 1]);
         j--;
      }
   }
}

int main()
{
   int list[] = {5,20,-5,0,10,2,4,9};
   std::cout << "list before sort: ";
   std::copy(std::begin(list), std::end(list), std::ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;
   insertion_sort<int>(list, 8);
   std::copy(std::begin(list), std::end(list), std::ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;

   return 0;
}