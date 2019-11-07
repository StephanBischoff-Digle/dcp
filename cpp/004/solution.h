#pragma once

#include <vector>

int find_lowest_missing(std::vector<int>& input) {
    for (std::size_t i = 0; i < input.size();) {
        auto current = input[i];

        if (current > 0 && static_cast<std::size_t>(current) <= input.size()) {
            if (static_cast<std::size_t>(current - 1) == i) {
                i++;
                continue;
            }

            auto other = input[static_cast<std::size_t>(current - 1)];
            input[static_cast<std::size_t>(current - 1)] = current;
            input[i] = other;
        } else {
            i++;
        }
    }

    for (std::size_t i = 0; i <= input.size(); i++) {
        if (i + 1 != static_cast<std::size_t>(input[i])) {
            return static_cast<int>(i + 1);
        }
    }

    return static_cast<int>(input.size());
}
