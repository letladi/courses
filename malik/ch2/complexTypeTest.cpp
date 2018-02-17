#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "complexType.h"

TEST_CASE("#conjugate")
{
    complexType c(4, 2);
    complexType expected(4, -2);
    REQUIRE( c.conjugate() == expected);
}

TEST_CASE("#~ should return the conjugate")
{
    complexType c(2, 4);
    complexType expected(2, -4);
    REQUIRE( ~c == expected );
}

TEST_CASE("#! returns the absolute value")
{
    complexType c(2, 4);
    double absoluteValue = 4.47213595499958;
    REQUIRE ( !c == absoluteValue);
}