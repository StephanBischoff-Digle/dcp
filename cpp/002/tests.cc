#include "solution.h"

#include "gtest/gtest.h"

#include <cstdint>
#include <vector>


TEST(d002, readme_01) {
    std::vector<int32_t> input{1, 2, 3, 4, 5};
    std::vector<int32_t> output{120, 60, 40, 30, 24};
    ASSERT_EQ(with_divide(input), output);
}

TEST(d002, readme_02) {
    std::vector<int32_t> input{3, 2, 1};
    std::vector<int32_t> output{2, 3, 6};
    ASSERT_EQ(with_divide(input), output);
}


