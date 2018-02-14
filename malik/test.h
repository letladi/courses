#include <string>

template <typename T>
void assertEqual(T expected, T actual, std::string msg);

void assertEqual(std::string expected, std::string actual, std::string msg);

void suite(std::string);