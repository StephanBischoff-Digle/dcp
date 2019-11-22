#include "gtest/gtest.h"
#include "solution.h"

TEST(d007, init) {
    std::string msg = "111";

    ASSERT_EQ(recursive_decodings(msg), 3);
}


