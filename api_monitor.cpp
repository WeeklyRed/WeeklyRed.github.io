//api_monitor.cpp

#include "api_monitor.hpp"

#include <unordered_map>
#include <algorithm>




std::pair<std::vector<std::string>, int>
find_most_frequent_endpoints(const std::vector<std::string>& api_logs) {
    std::unordered_map<std::string, int> api_call_count;
    int max_count = 0;

    for (const auto& endpoint : api_logs) {
        int count = ++api_call_count[endpoint];
        if (count > max_count) {
            max_count = count;
        }
    }

    std::vector<std::string> most_frequent;
    if (max_count == 0) {
        return {most_frequent, 0};
    }

    for (const auto& entry : api_call_count) {
        if (entry.second == max_count) {
            most_frequent.push_back(entry.first);
        }
    }

    std::sort(most_frequent.begin(), most_frequent.end());
    return {most_frequent, max_count};
}