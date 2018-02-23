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

    SECTION("should initialize number with a sign")
    {
        largeIntegers x("355");
        REQUIRE( x.getNumber() == "355" );

        largeIntegers y("355", false);
        REQUIRE( y.getNumber() == "-355" );
    }

    SECTION("#+")
    {
        largeIntegers a("15141064006880241877413928");
        largeIntegers b("159881888969344453055355700601287650987");
        largeIntegers sum = a + b;
        largeIntegers expectedSum("159881888969359594119362580843165064915");

        REQUIRE( sum.getNumber() == expectedSum.getNumber() );
    }

    SECTION("#+, should allow adding negative numbers")
    {
        largeIntegers x("1540902621461995147", false);
        largeIntegers y("115113481099902151516161", false);
        largeIntegers sum = x + y;
        largeIntegers expectedSum("-115115022002523613511308");

        REQUIRE( sum.getNumber() == expectedSum.getNumber() );
    }

    SECTION("#+, when a large negative number an a small positive number, it should return a negative number")
    {
        largeIntegers x("15421546141461904161614", false);
        largeIntegers y("123516126161433211");
        largeIntegers sum = x + y;
        largeIntegers expectedSum("-15421422625335742728403");

        REQUIRE( sum.getNumber() == expectedSum.getNumber() );
    }

    SECTION("#>, should return true if the first number is greater than the first")
    {
        largeIntegers x("1514614616415140008009261");
        largeIntegers y("1516143614694156146");

        REQUIRE ( (x > y) == true);
    }

    SECTION("#>, a positive number is greater than a positive number")
    {
        largeIntegers x("1514614616415140008009261", false);
        largeIntegers y("1516143614694156146");

        REQUIRE ( (y > x) == true);
    }

    SECTION("#>, a large negative number is less than a small negative number")
    {
        largeIntegers x("1514614616415140008009261", false);
        largeIntegers y("1516143614694156146", false);

        REQUIRE ( (y > x) == true);
    }

    {
        largeIntegers x("1514614616415140008009261", false);
        largeIntegers y("1516143614694156146");

        REQUIRE ( (y > x) == true);
    }

    SECTION("#>, a number with the same sign and same length but differing digits can be greater than another")
    {
        largeIntegers x("1514614616415140808009261");
        largeIntegers y("1514614616415140008009261");

        REQUIRE( (x > y) == true );
    }

    SECTION("#>, a number with the same sign (both negative) and same length but differing digits can be greater than another")
    {
        largeIntegers x("1514614616415140808009261", false);
        largeIntegers y("1514614616415140908009261", false);

        REQUIRE( (x > y) == true );
    }  

    SECTION("#<, a number with the same sign (both negative) and same length but differing digits can be greater than another")
    {
        largeIntegers x("15146146164151");
        largeIntegers y("1514614616415140908009261");

        REQUIRE( (x < y) == true );
    }  

    SECTION("#==, equal numbers wit equals sign are equal")
    {
        largeIntegers x("1516143614694156146");
        largeIntegers y("1516143614694156146");

        REQUIRE( (x == y) == true );
    }

    SECTION("#==, equal numbers with differing signs are not equal")
    {
        largeIntegers x("1516143614694156146", false);
        largeIntegers y("1516143614694156146");

        REQUIRE( (x == y) == false );
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

    SECTION("#=, should be able to assign one number to another")
    {
        largeIntegers x("99752648204682486202");
        largeIntegers y = x;

        x.setNumbers("15415641");

        REQUIRE( y.getNumber() ==  "99752648204682486202");
        REQUIRE( x.getNumber() == "15415641");
        REQUIRE( (x == y) == false);
    }
}
