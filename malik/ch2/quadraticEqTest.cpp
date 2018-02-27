#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "quadraticEq.h"
#include "complexType.h"

TEST_CASE("quadraticEq")
{
    SECTION("#getCoefficients")
    {
        quadraticEq eq(2, 2, 18);
        double a, b, c;
        eq.getCoefficients(a, b, c);

        REQUIRE( a == 2 );
        REQUIRE( b == 2 );
        REQUIRE( c == 18 );
    }

    SECTION("#+")
    {
        quadraticEq eq(2, 2, 18);
        quadraticEq eq2(4, -4, 8);

        quadraticEq sum = eq + eq2;
        quadraticEq expected(6, -2, 26);

        REQUIRE( sum == expected );
    }

    SECTION("#-")
    {
        quadraticEq eq(2, 2, 18);
        quadraticEq eq2(4, -4, 8);

        quadraticEq difference = eq - eq2;
        quadraticEq expected(-2, 6, 10);

        REQUIRE( difference == expected );
    }

    SECTION("#==")
    {
        quadraticEq eq(2, 2, 18);
        quadraticEq eq2(2, 2, 18);

        REQUIRE( eq == eq2 );
    }

    SECTION("#==")
    {
        quadraticEq eq(2, 2, 18);
        quadraticEq eq2(-2, 5, 18);

        REQUIRE( eq != eq2 );
    }

    SECTION("#realRoots")
    {
        quadraticEq eq(1, 3, -4);
        double x1, x2;
        eq.realRoots(x1, x2);
        REQUIRE( x1 == -4 );
        REQUIRE( x2 == 1 );
    }

    SECTION("#complexRoots")
    {
        quadraticEq eq(5, 2, 1);
        complexType c1(-0.2, -0.4);
        complexType c2(-0.2, 0.4);

        complexType c3, c4;
        eq.complexRoots(c3, c4);
        REQUIRE( c3 == c1 );
        REQUIRE( c4 == c2 );
    }

    SECTION("#root")
    {
        quadraticEq eq(-4, 12, -9);
        double x = eq.root();
        double expectedRoot = 1.5;

        REQUIRE( expectedRoot == x);
    }
}
