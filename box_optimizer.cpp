//box_optimizer.cpp
#include "box_optimizer.hpp"
#include <unordered_map>




std::pair<int, int> find_item_pair_for_exact_box_fit(const std::vector<int>& item_weights, int box_capacity) {
    std::unordered_map<int, int> weight_to_index; // weight -> index

    for (int i = 0; i < static_cast<int>(item_weights.size()); ++i) {
        int weight = item_weights[i];
        int remaining = box_capacity - weight;

        auto it = weight_to_index.find(remaining);
        if (it != weight_to_index.end() && it->second != i) {
            int idx1 = it->second;
            int idx2 = i;
            if (idx1 > idx2) std::swap(idx1, idx2);
            return {idx1, idx2};
        }

        // Store first occurrence of this weight
        if (weight_to_index.find(weight) == weight_to_index.end()) {
            weight_to_index[weight] = i;
        }
    }

    return {-1, -1};
}
