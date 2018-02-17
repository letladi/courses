#include "complexType.h"
#include "../test.cpp"

int main() {
    suite("complexType");
    complexType c1(2, 3);
    complexType c2(4, 4);
    complexType c3(0, 1);

    complexType subtracted = c1 - c2;
    complexType added = c1 + c2;
    complexType dividedByZero = c2 / c3;
    complexType divided = c2 / c1;

    complexType expectedSubtraction(-2, -1);
    complexType expectedAddition(6, 7);
    complexType expectedDivisionByZero(0, 0);
    complexType expectedDivision(1.5384615384615385, -0.3076923076923077);


    assertEqual(true, expectedSubtraction == subtracted, "(2, 3) - (4, 4) = (-2, -1)");
    assertEqual(true, expectedAddition == added, "(2, 3) + (4, 4) = (6, 7)");
    assertEqual(true, dividedByZero == expectedDivisionByZero, "(4, 4) / (0, 1) = (0, 0)");
    assertEqual(true, divided == expectedSubtraction, "(4, 4) / (2, 3) = (1.5384615384615385, -0.3076923076923077)");
}