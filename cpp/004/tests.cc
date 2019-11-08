#include <vector>

#include "gtest/gtest.h"
#include "solution.h"

TEST(d004, readme_01) {
    std::vector<int> input{3, 4, -1, 1};

    ASSERT_EQ(find_lowest_missing(input), 2);
}

TEST(d004, readme_02) {
    std::vector<int> input{1, 2, 0};

    ASSERT_EQ(find_lowest_missing(input), 3);
}
