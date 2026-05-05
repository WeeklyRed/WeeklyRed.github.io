//customer_loyalty.hpp
#pragma once

#include <map>
#include <string>

std::map<int, std::string> build_loyalty_tier_map();

std::string get_tier_for_customer_score(const std::map<int, std::string>& tier_map, int score);