#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "min_merge_cost.hpp"
#include "sort_sqn.hpp"

TEST_CASE("min_merge_cost basic example") {
    std::vector<int> files = {10, 20, 30};
    REQUIRE(min_merge_cost(files) == 90);
}

TEST_CASE("min_merge_cost empty and single file") {
    REQUIRE(min_merge_cost({}) == 0);
    REQUIRE(min_merge_cost({50}) == 0);
}

TEST_CASE("min_merge_cost multiple files") {
    std::vector<int> files = {5, 10, 20, 30};
    REQUIRE(min_merge_cost(files) == 115);
}

TEST_CASE("top_sqrtN_sorted basic example") {
    std::vector<int> v = {3, -1, 7, -5, 2, 9, -2, 8, 0};
    std::vector<int> expected = {9, 8, 7};

    REQUIRE(top_sqrtN_sorted(v) == expected);
}

TEST_CASE("top_sqrtN_sorted empty vector") {
    std::vector<int> v = {};
    std::vector<int> expected = {};

    REQUIRE(top_sqrtN_sorted(v) == expected);
}

TEST_CASE("top_sqrtN_sorted with duplicates") {
    std::vector<int> v = {4, 9, 9, 1, 2, 9, 3, 8, 8, 7};
    std::vector<int> expected = {9, 9, 9, 8};

    REQUIRE(top_sqrtN_sorted(v) == expected);
}

TEST_CASE("top_sqrtN_sorted small vector") {
    std::vector<int> v = {6, 2};
    std::vector<int> expected = {6, 2};

    REQUIRE(top_sqrtN_sorted(v) == expected);
}