#pragma once

#include <vector>
#include <algorithm>


template <typename T>
T recursive_highest_non_adjacent(
        const typename std::vector<T>::const_iterator& start,
        const typename std::vector<T>::const_iterator& end) {

    if (start >= end) {
        return 0;
    }

    return std::max(
            recursive_highest_non_adjacent<T>(start + 1, end),
            *start + recursive_highest_non_adjacent<T>(start + 2, end));

}
