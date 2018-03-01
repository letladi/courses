#define CATCH_CONFIG_MAIN

#include "../../catch.hpp"
#include "romanType.h"

TEST_CASE("romanType")
{
    SECTION("#convertToDecimal")
    {
        romanType rome("XIX");
        CHECK( rome.romanToDecimal() == 19 );
    }

    SECTION("#romanToDecimal")
    {
        romanType roman(5);

        CHECK( roman.decimalToRoman() == "V" );

        roman.setDecimalNum(10);
        CHECK( roman.decimalToRoman() == "X" );

        roman.setDecimalNum(4);
        CHECK( roman.decimalToRoman() == "IV" );

        roman.setDecimalNum(9);
        CHECK( roman.decimalToRoman() == "IX" );

        roman.setDecimalNum(39);
        CHECK( roman.decimalToRoman() == "XXXIX" );

        roman.setDecimalNum(49);
        CHECK( roman.decimalToRoman() == "XXXXIX" );

        roman.setDecimalNum(40);
        CHECK( roman.decimalToRoman() == "XXXX" );

        roman.setDecimalNum(190);
        CHECK( roman.decimalToRoman() == "CLXXXX" );

        roman.setDecimalNum(3);
        CHECK( roman.decimalToRoman() == "III" );

        roman.setDecimalNum(8);
        CHECK( roman.decimalToRoman() == "VIII" );
    }
}
