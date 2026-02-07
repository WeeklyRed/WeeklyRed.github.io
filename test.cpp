#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_DISABLE_BREAK_INTO_DEBUGGER
#include "catch2/catch.hpp"
#include "prime.hpp"


TEST_CASE("isPrimeHalf") {
    
    bool test;
    test = isPrimeHalf(1);
    REQUIRE(!test);
    test = isPrimeHalf(2);
    REQUIRE(test);
    test = isPrimeHalf(5);
    REQUIRE(test);
    test = isPrimeHalf(11);
    REQUIRE(test);
    test = isPrimeHalf(12);
    REQUIRE(!test);
}

TEST_CASE("isPrimeSqrt") {

    bool test;
    test = isPrimeSqrt(1);
    REQUIRE(!test);
    test = isPrimeSqrt(2);
    REQUIRE(test);
    test = isPrimeSqrt(5);
    REQUIRE(test);
    test = isPrimeSqrt(11);
    REQUIRE(test);
    test = isPrimeSqrt(12);
    REQUIRE(!test);
    
}

TEST_CASE("countModOpsHalf(lo, hi)") {
    long long int test;
    test = countModOpsHalf(1, 2);
    REQUIRE(test == 0);
    test = countModOpsHalf(3, 5);
    REQUIRE(test == 3);
    test = countModOpsHalf(10, 20);
    REQUIRE(test == 23);
}

TEST_CASE("countModOpsSqrt(lo, hi)") {

    long long int test;
    test = countModOpsSqrt(1, 2);
    REQUIRE(test == 0);
    test = countModOpsSqrt(3, 5);
    REQUIRE(test == 3);
    test = countModOpsSqrt(10, 20);
    REQUIRE(test == 16);
    

}