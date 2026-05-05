//cart_analysis.cpp

#include "cart_analysis.hpp"

#include <unordered_map>
#include <algorithm>

std::vector<std::string> find_common_products_across_carts(const std::vector<std::vector<std::string>>& carts);

std::vector<std::string> find_common_products_across_carts(const std::vector<std::vector<std::string>>& carts) {
    std::vector<std::string> result;
    if (carts.empty()) {
        return result;
    }

    std::unordered_map<std::string, int> product_count;

    for (const auto& cart : carts) {
        for (const auto& product : cart) {
            ++product_count[product];
        }
    }

    int n = static_cast<int>(carts.size());
    for (const auto& entry : product_count) {
        if (entry.second == n) {
            result.push_back(entry.first);
        }
    }

    std::sort(result.begin(), result.end());
    return result;
}
