#pragma once

#include <algorithm>
#include <vector>

template <typename T>
T recursive_highest_non_adjacent(
        const typename std::vector<T>::const_iterator& start,
        const typename std::vector<T>::const_iterator& end) {

    if (start >= end) {
        return 0;
    }

    return std::max(recursive_highest_non_adjacent<T>(start + 1, end),
                    *start + recursive_highest_non_adjacent<T>(start + 2, end));
}

template <typename T>
T dynamic_highest_non_adjacent(const std::vector<T>& list) {
    if (list.size() <= 2) {
        T highest = 0;
        for (const T& i : list) {
            highest = std::max(highest, i);
        }
        return highest;
    }

    std::vector<T> cache(list.size(), T{});
    cache[0] = std::max(0, list[0]);
    cache[1] = std::max(cache[0], list[1]);

    for (std::size_t i = 2; i < list.size(); i++) {
        T tmp = list[i];
        cache[i] = std::max(tmp + cache[i - 2], cache[i - 1]);
    }

    return cache.back();
}

template <typename T>
T highest_non_adjacent(const std::vector<T>& list) {
    if (list.size() <= 2) {
        T highest = 0;
        for (const T& i : list) {
            highest = std::max(highest, i);
        }
        return highest;
    }

    T a = std::max(0, list[0]);
    T b = std::max(a, list[1]);

    std::for_each(list.begin() + 2, list.end(), [&a, &b](const T& i) {
        T tmp = b;
        b = std::max(b, a + i);
        a = tmp;
    });

    return std::max(a, b);
}
