#include "gtest/gtest.h"
#include "solution.h"

TEST(d008, readme) {
    btree<int> tree {0,
        new btree<int>{1},
        new btree<int>{0,
            new btree<int>{1,
                new btree<int>{1},
                new btree<int>{1}},
            new btree<int>{0}}};

    ASSERT_EQ(tree.n_unival_subtrees(), 5);
}


