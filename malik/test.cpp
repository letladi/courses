#include <iostream>
#include "test.h"

template <typename T>
void assertEqual(T expected, T actual, std::string msg) {
    bool testPassed = expected == actual;

    if (testPassed) {
        std::cout << "\033[1;32m \t✔   " << msg << "\033[0m\n" << std::endl;
    } else {
        std::cout << "\033[1;31m \t✘   " << msg << " (expected " << expected << " to equal " << actual << ")" << "\033[0m\n" << std::endl;
    }
}

void assertEqual(std::string expected, std::string actual, std::string msg) {
    bool testPassed = expected.compare(actual) == 0;

    if (testPassed) {
        std::cout << "\033[1;32m \t✔   " << msg << "\033[0m\n" << std::endl;
    } else {
        std::cout << "\033[1;31m \t✘   " << msg << " (expected " << expected << " to equal " << actual << ")" << "\033[0m\n" << std::endl;
    }
}

void suite(std::string suiteName) {
    std::cout << "\033[1;34m " << suiteName << "\033[0m\n" << std::endl;
}