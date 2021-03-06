#include <random>
#include <vector>

#include "gtest/gtest.h"
#include "solution.h"

TEST(d006, normal) {

    // Generate test
    std::size_t n_cases = 14;
    xor_linked_list lst;
    std::vector<std::int32_t> cases(n_cases);

    std::default_random_engine generator;
    std::uniform_int_distribution<std::int32_t> dist(1, 10);

    for (std::size_t i = 0; i < cases.size(); ++i) {
        auto data = dist(generator);
        cases[i] = data;
        lst.add(data);
    }

    // TEST
    for (std::size_t i = 0; i < cases.size(); ++i) {
        ASSERT_EQ(lst.get(i), cases[i]);
    }
}

TEST(d006, bounds_check_size) {
    xor_linked_list lst;

    ASSERT_EQ(lst.size(), 0);

    lst.add(1);
    ASSERT_EQ(lst.size(), 1);
}

TEST(d006, bounds_check_return) {
    xor_linked_list lst;

    ASSERT_EQ(lst.get(0), std::nullopt);

    lst.add(1);

    ASSERT_NE(lst.get(0), std::nullopt);
}
