// tests/test_a13.cpp
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "api_monitor.hpp"
#include "box_optimizer.hpp"
#include "cart_analysis.hpp"
#include "customer_loyalty.hpp"

#include <vector>
#include <string>
#include <map>
#include <utility>

// -------------------- api_monitor.cpp --------------------

TEST_CASE("empty API logs returns empty vector and count 0", "[t0]") {
    std::vector<std::string> logs = {};

    auto result = find_most_frequent_endpoints(logs);

    REQUIRE(result.first.empty());
    REQUIRE(result.second == 0);
}

TEST_CASE("single most frequent API endpoint is found", "[t1]") {
    std::vector<std::string> logs = {
        "/login", "/cart", "/login", "/products", "/login"
    };

    auto result = find_most_frequent_endpoints(logs);

    REQUIRE(result.first == std::vector<std::string>{"/login"});
    REQUIRE(result.second == 3);
}

TEST_CASE("multiple API endpoints tied for most frequent are returned sorted", "[t2]") {
    std::vector<std::string> logs = {
        "/login", "/cart", "/login", "/cart", "/products"
    };

    auto result = find_most_frequent_endpoints(logs);

    REQUIRE(result.first == std::vector<std::string>{"/cart", "/login"});
    REQUIRE(result.second == 2);
}

TEST_CASE("all API endpoints appearing once are returned sorted", "[t3]") {
    std::vector<std::string> logs = {
        "/b", "/a", "/c"
    };

    auto result = find_most_frequent_endpoints(logs);

    REQUIRE(result.first == std::vector<std::string>{"/a", "/b", "/c"});
    REQUIRE(result.second == 1);
}

// -------------------- box_optimizer.cpp --------------------

TEST_CASE("finds basic pair that exactly fits box", "[t4]") {
    std::vector<int> weights = {2, 7, 11, 15};

    auto result = find_item_pair_for_exact_box_fit(weights, 9);

    REQUIRE(result == std::make_pair(0, 1));
}

TEST_CASE("finds pair using duplicate weights", "[t5]") {
    std::vector<int> weights = {5, 5};

    auto result = find_item_pair_for_exact_box_fit(weights, 10);

    REQUIRE(result == std::make_pair(0, 1));
}

TEST_CASE("returns negative pair when no exact fit exists", "[t6]") {
    std::vector<int> weights = {1, 2, 3, 4};

    auto result = find_item_pair_for_exact_box_fit(weights, 8);

    REQUIRE(result == std::make_pair(-1, -1));
}

TEST_CASE("finds pair including zero weight item", "[t7]") {
    std::vector<int> weights = {0, 4, 5};

    auto result = find_item_pair_for_exact_box_fit(weights, 4);

    REQUIRE(result == std::make_pair(0, 1));
}

TEST_CASE("finds pair with negative weight", "[t8]") {
    std::vector<int> weights = {-2, 6, 10};

    auto result = find_item_pair_for_exact_box_fit(weights, 4);

    REQUIRE(result == std::make_pair(0, 1));
}

// -------------------- cart_analysis.cpp --------------------

TEST_CASE("empty carts returns empty result", "[t9]") {
    std::vector<std::vector<std::string>> carts = {};

    auto result = find_common_products_across_carts(carts);

    REQUIRE(result.empty());
}

TEST_CASE("finds products common across all carts", "[t10]") {
    std::vector<std::vector<std::string>> carts = {
        {"apple", "banana", "milk"},
        {"banana", "milk", "eggs"},
        {"milk", "banana", "bread"}
    };

    auto result = find_common_products_across_carts(carts);

    REQUIRE(result == std::vector<std::string>{"banana", "milk"});
}

TEST_CASE("returns empty when no products are common across all carts", "[t11]") {
    std::vector<std::vector<std::string>> carts = {
        {"apple", "banana"},
        {"milk", "eggs"},
        {"bread", "cheese"}
    };

    auto result = find_common_products_across_carts(carts);

    REQUIRE(result.empty());
}

TEST_CASE("common products are returned alphabetically", "[t12]") {
    std::vector<std::vector<std::string>> carts = {
        {"banana", "apple"},
        {"apple", "banana"},
        {"banana", "apple"}
    };

    auto result = find_common_products_across_carts(carts);

    REQUIRE(result == std::vector<std::string>{"apple", "banana"});
}

// -------------------- customer_loyalty.cpp --------------------

TEST_CASE("build loyalty tier map contains correct tiers", "[t13]") {
    std::map<int, std::string> tiers = build_loyalty_tier_map();

    REQUIRE(tiers.size() == 4);
    REQUIRE(tiers[0] == "Bronze");
    REQUIRE(tiers[500] == "Silver");
    REQUIRE(tiers[1000] == "Gold");
    REQUIRE(tiers[2000] == "Platinum");
}

TEST_CASE("customer scores return correct loyalty tiers", "[t14]") {
    std::map<int, std::string> tiers = build_loyalty_tier_map();

    REQUIRE(get_tier_for_customer_score(tiers, 0) == "Bronze");
    REQUIRE(get_tier_for_customer_score(tiers, 499) == "Bronze");

    REQUIRE(get_tier_for_customer_score(tiers, 500) == "Silver");
    REQUIRE(get_tier_for_customer_score(tiers, 999) == "Silver");

    REQUIRE(get_tier_for_customer_score(tiers, 1000) == "Gold");
    REQUIRE(get_tier_for_customer_score(tiers, 1999) == "Gold");

    REQUIRE(get_tier_for_customer_score(tiers, 2000) == "Platinum");
    REQUIRE(get_tier_for_customer_score(tiers, 5000) == "Platinum");
}

TEST_CASE("empty loyalty tier map returns empty string", "[t15]") {
    std::map<int, std::string> tiers = {};

    REQUIRE(get_tier_for_customer_score(tiers, 1000) == "");
}

TEST_CASE("score below first tier returns first tier", "[t16]") {
    std::map<int, std::string> tiers = build_loyalty_tier_map();

    REQUIRE(get_tier_for_customer_score(tiers, -100) == "Bronze");
}