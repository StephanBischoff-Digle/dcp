#pragma once

#include <unordered_set>
#include <vector>

template <typename T>
bool sums_to_k(const T& k, const std::vector<T>& vec) {
    std::unordered_set<T> seen;
    for (const auto num : vec) {
        if (seen.find(k - num) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}
