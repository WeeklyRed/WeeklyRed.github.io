#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_DISABLE_BREAK_INTO_DEBUGGER
#include "catch2/catch.hpp"
#include "reverse.hpp"


TEST_CASE("Testing even length integers") 
{
    //std::shared_ptr<long long> temp = std::make_shared<long long>(0);
    {
    INFO("Check for even length arrays");
        int arr1[] = {1, 2, 3, 4};
        int arr2[] = {4, 3, 2, 1};
        reverse_array(arr1, (sizeof(arr1)/sizeof(arr1[0])));
        CHECK(checkReverse(arr1, arr2));

        int arr3[] = {5, 6};
        int arr4[] = {6, 5};
        reverse_array(arr3, (sizeof(arr3)/sizeof(arr3[0])));
        CHECK(checkReverse(arr3, arr4));

    }    
}

TEST_CASE("Testing odd length integers") 
{
    //std::shared_ptr<long long> temp = std::make_shared<long long>(0);
    {
    INFO("Check for odd length arrays");
        int arr1[] = {1, 2, 3};
        int arr2[] = {3, 2, 1};
        reverse_array(arr1, (sizeof(arr1)/sizeof(arr1[0])));
        CHECK(checkReverse(arr1, arr2));

        int arr3[] = {5, 6, 7, 8, 9};
        int arr4[] = {9, 8, 7, 6, 5};
        reverse_array(arr3, (sizeof(arr3)/sizeof(arr3[0])));
        CHECK(checkReverse(arr3, arr4));

    }    
}

TEST_CASE("Testing palindrome array") 
{
    //std::shared_ptr<long long> temp = std::make_shared<long long>(0);
    {
    INFO("Check for palindrome array");
        int arr1[] = {1, 2, 2, 1};
        int arr2[] = {1, 2, 2, 1};
        reverse_array(arr1, (sizeof(arr1)/sizeof(arr1[0])));
        CHECK(checkReverse(arr1, arr2));

        int arr3[] = {5, 6, 5};
        int arr4[] = {5, 6, 5};
        reverse_array(arr3, (sizeof(arr3)/sizeof(arr3[0])));
        CHECK(checkReverse(arr3, arr4));

    }    
}

