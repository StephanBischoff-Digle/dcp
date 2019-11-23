#include "gtest/gtest.h"
#include "solution.h"

#include <vector>

TEST(d009, recursive_readme_1) {
    std::vector<int> v = {2, 4, 6, 2, 5};

    ASSERT_EQ(recursive_highest_non_adjacent<int>(v.begin(), v.end()), 13);
}

TEST(d009, recursive_readme_2) {
    std::vector<int> v = {5, 1, 1, 5};

    ASSERT_EQ(recursive_highest_non_adjacent<int>(v.begin(), v.end()), 10);
}


