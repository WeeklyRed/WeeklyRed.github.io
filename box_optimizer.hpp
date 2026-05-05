//box_optimizer.hpp

#pragma once

#include <vector>
#include <utility>

std::pair<int, int> find_item_pair_for_exact_box_fit(const std::vector<int>& item_weights, int box_capacity);