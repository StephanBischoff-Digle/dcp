#pragma once

#include <cstdint>
#include <functional>
#include <numeric>
#include <vector>

template <typename T>
std::vector<T> with_divide(const std::vector<T>& input) {
    T product = std::accumulate(input.begin(), input.end(), T{1},
                                std::multiplies<T>());
    std::vector<T> result;

    for (auto&& x : input) {
        result.emplace_back(product / x);
    }

    return result;
}
