#ifndef SORT_SQN_HPP
#define SORT_SQN_HPP

#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

std::vector<int> top_sqrtN_sorted(const std::vector<int>& v) {
    int n = static_cast<int>(v.size());

    if (n == 0) {
        return {};
    }

    int k = static_cast<int>(std::ceil(std::sqrt(n)));

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int value : v) {
        if (static_cast<int>(pq.size()) < k) {
            pq.push(value);
        } else if (value > pq.top()) {
            pq.pop();
            pq.push(value);
        }
    }

    std::vector<int> result;
    result.reserve(k);

    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    std::reverse(result.begin(), result.end());

    return result;
}

#endif