#ifndef MIN_MERGE_COST_HPP
#define MIN_MERGE_COST_HPP

#include <vector>
#include <queue>
#include <functional>

int min_merge_cost(const std::vector<int>& files) {
    if (files.size() <= 1) {
        return 0;
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int size : files) {
        pq.push(size);
    }

    int totalCost = 0;

    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        int merged = first + second;
        totalCost += merged;

        pq.push(merged);
    }

    return totalCost;
}

#endif