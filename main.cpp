#include <iostream>
using namespace std;

#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "RationalNumber.h"

TEST_CASE("Rational Numbers") 
{
    SECTION("Test Constructor")
    {
        RationalNumber num(1, 2);
        REQUIRE(1 == num.getNumerator());
        REQUIRE(2 == num.getDenominator());
    }

    SECTION("Test 0 in the denominator")
    {
        RationalNumber* p_num;
        REQUIRE_THROWS(p_num = new RationalNumber(1, 0));
    }

    SECTION("Test toString()")
    {
        RationalNumber num(1, 2);
        REQUIRE("1/2" == num.toString());
        
        RationalNumber num1(2, 4);
        REQUIRE("2/4" == num1.toString());
    }

    SECTION("Test Compare")
    {
        RationalNumber num1(1, 2);
        RationalNumber num2(1, 2);

        REQUIRE(num1.compareEquals(num2));
        REQUIRE(num2.compareEquals(num1));

        RationalNumber num3(1, 2);
        RationalNumber num4(2, 4);
        
        // REQUIRE(num3.getReducedNumerator()==1);
        // REQUIRE(num3.getReducedDenominator()==2);

        // REQUIRE(num4.getReducedNumerator()==1);
        // REQUIRE(num4.getReducedDenominator()==2);

        REQUIRE(num3.compareEquals(num4));
        REQUIRE(num4.compareEquals(num3));

        RationalNumber n5(4,2);
        RationalNumber n6(2,1);

        RationalNumber n7(0, 9);
        RationalNumber n8(0, 10);

        REQUIRE(n5.compareEquals(n6));
        REQUIRE(n6.compareEquals(n5));

        REQUIRE(n7.compareEquals(n8));
    }
    
    SECTION("Test add()")
    {
        RationalNumber num1(1, 2);
        RationalNumber num2(3, 4);
        RationalNumber result(5, 4);
        REQUIRE(result.compareEquals(num1.add(num2)));
    }
}