#include "solution.h"

#include <iostream>

#include "gtest/gtest.h"


TEST(Day003Test, serialize_root) {
    Node n{"v"};
    std::string solution = 
        "v # #";

    ASSERT_EQ(serialize(n), solution);
}

TEST(Day003Test, serialize_full_depth2) {
    Node n{"v", "l", "r"};
    std::string solution = 
        "v l # # r # #";

    ASSERT_EQ(serialize(n), solution);
}

TEST(Day003Test, serialize_full_left) {
    Node n{"v"};
    n.add_left("l");
    n.left->add_left("ll");

    std::string solution = 
        "v l ll # # # #";

    ASSERT_EQ(serialize(n), solution);
}

TEST(Day003Test, serialize_full_right) {
    Node n{"v"};
    n.add_right("r");
    n.right->add_right("rr");
    std::string solution = 
        "v # r # rr # #";

    ASSERT_EQ(serialize(n), solution);
}


TEST(Day003Test, serialize_full_depth3) {
    Node n{"v", "l", "r"};
    n.left->add_left("ll");
    n.left->left->add_left("lll");
    n.left->left->add_right("llr");
    n.left->add_right("lr");
    n.left->right->add_left("lrl");
    n.left->right->add_right("lrr");
    n.right->add_left("rl");
    n.right->left->add_left("rll");
    n.right->left->add_right("rlr");
    n.right->add_right("rr");
    n.right->right->add_left("rrl");
    n.right->right->add_right("rrr");

    std::string solution = 
        "v l ll lll # # llr # # lr lrl # # lrr # # "
        "r rl rll # # rlr # # rr rrl # # rrr # #";

    ASSERT_EQ(serialize(n), solution);
}

TEST(Day003Test, deserialize) {
    ASSERT_EQ(true, false);
}
