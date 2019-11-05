#include "solution.h"

#include "gtest/gtest.h"
#include "dbg.h"


TEST(Day003Test, readme) {
    Node n;
    n.val = "Hello";
    n.left = nullptr;
    n.right = nullptr;
    dbg(n);

    ASSERT_EQ(true, false);
}


