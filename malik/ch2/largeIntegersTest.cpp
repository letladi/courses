#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "largeIntegers.h"

TEST_CASE("largeIntegers")
{
    SECTION("#getNumber, it should return the number as a string")
    {
        largeIntegers a("355");
        REQUIRE( a.getNumber() == "355");
    }

    SECTION("#+")
    {
        largeIntegers a("15141064006880241877413928");
        largeIntegers b("159881888969344453055355700601287650987");
        largeIntegers sum = a + b;
        largeIntegers expectedSum("159881888969359594119362580843165064915");

        REQUIRE( sum.getNumber() == expectedSum.getNumber() );
    }

    SECTION("#-")
    {
        largeIntegers x("24206470246820099924145676");
        largeIntegers y("99752648204682486202");
        largeIntegers difference = x - y;
        largeIntegers expectedDifference("24206370494171895241659474");

        REQUIRE( difference.getNumber() == expectedDifference.getNumber() );
    }

    SECTION("#-, the result should be negative if the difference is between a short number an a long")
    {
        largeIntegers x("24206470246820099924145676");
        largeIntegers y("99752648204682486202");
        largeIntegers difference = y - x;
        largeIntegers expectedDifference("-24206370494171895241659474");

        REQUIRE( difference.getNumber() == expectedDifference.getNumber() );
    }
}
