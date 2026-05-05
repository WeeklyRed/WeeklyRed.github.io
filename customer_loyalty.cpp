//customer_loyalty.cpp

#include "customer_loyalty.hpp"

#include <iterator> // for std::prev

std::map<int, std::string> build_loyalty_tier_map();

std::string get_tier_for_customer_score(const std::map<int, std::string>& tier_map, int score);


std::map<int, std::string> build_loyalty_tier_map() {
    std::map<int, std::string> tiers;
    tiers[0]    = "Bronze";
    tiers[500]  = "Silver";
    tiers[1000] = "Gold";
    tiers[2000] = "Platinum";
    return tiers;
}

std::string get_tier_for_customer_score(const std::map<int, std::string>& tiers, int score) {
    if (tiers.empty()) {
        return "";
    }

    auto it = tiers.lower_bound(score);

    if (it == tiers.end()) {
        // Score is greater than the largest key
        auto last = tiers.end();
        --last;
        return last->second;
    }

    if (it->first == score) {
        // Exact match
        return it->second;
    }

    if (it == tiers.begin()) {
        // Score is less than the smallest key
        return it->second;
    }

    // it->first > score so the correct tier is the previous one
    auto prev_it = std::prev(it);
    return prev_it->second;
}
