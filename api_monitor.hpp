//api_monitor.hpp
#pragma once

#include <vector>
#include <string>
#include <utility>

std::pair<std::vector<std::string>, int>
find_most_frequent_endpoints(const std::vector<std::string>& api_logs);