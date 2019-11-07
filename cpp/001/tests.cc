#include "solution.h"

#include "gtest/gtest.h"

#include <cstdint>
#include <vector>


TEST(d001, find) {
    int64_t k = 17;
    std::vector<int64_t> list{10, 15, 3, 7};
    ASSERT_TRUE(sums_to_k(k, list));
}

TEST(d001, dont_find) {
    int64_t k = 5;
    std::vector<int64_t> list{10, 15, 3, 7};
    ASSERT_FALSE(sums_to_k(k, list));
}
