#include <iostream>
#include "romanType.h"

int main() {
    std::string input;
	std::string exitCommand("exit");
	romanType roman;

    do {
		std::cout << "Please enter some roman numeral number: ";
		std::getline(std::cin, input);

        if (input.compare(exitCommand) != 0) {
            roman.setRomanNum(input);
        }

		std::cout << "Here is the equivalent decimal number: " << roman.getDecimalNum() << std::endl << std::endl;

    } while (input.compare(exitCommand) != 0);

    std::cout << "\n***************\nGOOD BYE!\n***************\n";
}