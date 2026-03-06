// test_vector.cpp
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
//#include "vector.hpp"
#include <stdexcept>
#include <iostream>

TEST_CASE("Default constructor creates empty vector") {
    dsac::array::Vector<int> v;
    bool ok{true};
    REQUIRE(ok);
}



TEST_CASE("Testing functions") 
{
    dsac::array::Vector<int> v;
    dsac::array::Vector<int> empt;
    for(int i = 0; i <= 5; i++){
        v.push_back(i);
    }
    {
    INFO("Check capacity()");
        CHECK(v.capacity() == 8); 
    }
    {
    INFO("Check size()");
        CHECK(v.size() == 6); 
    }
    {
    INFO("Check empty()");
        CHECK(!v.empty()); 
        CHECK(empt.empty());
    }
    {
    INFO("Check operator[]()");
        CHECK(v.operator[](3) == 3); 
    }
    {
    INFO("Check at()");
        CHECK(v.at(2) == 2); 
    }
    {
    INFO("Check front()");
        CHECK(v.front() == 0); 
    }
    {
    INFO("Check back()");
        CHECK(v.back() == 5); 
    }
    {
    INFO("Check push_back()");
        v.push_back(10);
        CHECK(v.back() == 10); 
    }
    {
    INFO("Check pop_back()");
        v.pop_back();
        CHECK(v.back() == 5); 
    }
    {
    INFO("Check insert()");
        v.insert(3, 22);
        CHECK(v.at(3) == 22); 
    }
    {
    INFO("Check erase()");
        v.erase(3);
        CHECK(v.at(3) == 3); 
    }

}

