#define CATCH_CONFIG_MAIN

#include "../../catch.hpp"
#include "extRomanType.h"

TEST_CASE("extRomanType")
{
    SECTION("#+")
    {
        extRomanType rome1("V");
        extRomanType rome2("V");
        extRomanType sum = rome1 + rome2;
        CHECK( sum.romanToDecimal() == 10 );
        CHECK( sum.decimalToRoman() == "X");
    }

    SECTION("#-")
    {
        extRomanType rome1("X");
        extRomanType rome2("V");
        extRomanType difference = rome1 - rome2;

        CHECK( difference.romanToDecimal() == 5 );
        CHECK( difference.decimalToRoman() == "V");
    }

    SECTION("#*")
    {
        extRomanType rome1("X");
        extRomanType rome2("X");
        extRomanType product = rome1 * rome2;

        CHECK( product.romanToDecimal() == 100 );
        CHECK( product.decimalToRoman() == "C");
    }

    SECTION("#/")
    {
        extRomanType rome1("C");
        extRomanType rome2("X");
        extRomanType quotient = rome1 / rome2;

        CHECK( quotient.romanToDecimal() == 10 );
        CHECK( quotient.decimalToRoman() == "X");
    }

    SECTION("#++, prefix operator")
    {
        extRomanType rome("V");
        ++rome;

        CHECK( rome.romanToDecimal() == 6 );
        CHECK( rome.decimalToRoman() == "VI");
    }

    SECTION("#++, postfix operator")
    {
        extRomanType rome("V");
        rome++;

        CHECK( rome.romanToDecimal() == 6 );
        CHECK( rome.decimalToRoman() == "VI");
    }

    SECTION("#--, prefix operator")
    {
        extRomanType rome("V");
        --rome;

        CHECK( rome.romanToDecimal() == 4 );
        CHECK( rome.decimalToRoman() == "IV");
    }

    SECTION("#--, postfix operator")
    {
        extRomanType rome("V");
        rome--;

        CHECK( rome.romanToDecimal() == 4 );
        CHECK( rome.decimalToRoman() == "IV");
    }

}
