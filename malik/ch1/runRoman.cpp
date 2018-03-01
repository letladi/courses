#include <iostream>
#include "romanType.h"

int main() {
    std::string input;
	std::string exitCommand("exit");
	romanType roman;

    do {
		std::cin >> roman;
		std::cout << roman;
    } while (input.compare(exitCommand) != 0);

    std::cout << "\n***************\nGOOD BYE!\n***************\n";
}
