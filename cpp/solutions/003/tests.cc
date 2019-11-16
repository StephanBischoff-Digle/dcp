#include <iostream>

#include "gtest/gtest.h"
#include "solution.h"

TEST(d003, serialize_root) {
    Node n{"v"};
    std::string solution = "v # #";

    ASSERT_EQ(serialize(n), solution);
}

TEST(d003, serialize_full_depth2) {
    Node n{"v", new Node{"l"}, new Node{"r"}};

    std::string solution = "v l # # r # #";

    ASSERT_EQ(serialize(n), solution);
}

TEST(d003, serialize_full_left) {
    Node n{"v", new Node{"l", new Node{"ll"}}};

    std::string solution = "v l ll # # # #";

    ASSERT_EQ(serialize(n), solution);
}

TEST(d003, serialize_full_right) {
    Node n{"v", nullptr, new Node{"r", nullptr, new Node{"rr"}}};

    std::string solution = "v # r # rr # #";

    ASSERT_EQ(serialize(n), solution);
}

TEST(d003, serialize_full_depth3) {
    Node n{"v",
           new Node{"l", new Node{"ll", new Node{"lll"}, new Node{"llr"}},
                    new Node{"lr", new Node{"lrl"}, new Node{"lrr"}}},
           new Node{"r", new Node{"rl", new Node{"rll"}, new Node{"rlr"}},
                    new Node{"rr", new Node{"rrl"}, new Node{"rrr"}}}};

    std::string solution =
            "v l ll lll # # llr # # lr lrl # # lrr # # "
            "r rl rll # # rlr # # rr rrl # # rrr # #";

    ASSERT_EQ(serialize(n), solution);
}

////////////////////////////////////////////////////////////
TEST(d003, equivalence_shallow) {
    std::string s{"v # #"};

    ASSERT_EQ(serialize(deserialize(s)), s);
}

TEST(d003, equivalence_left) {
    std::string s{"v l ll # # # #"};

    ASSERT_EQ(serialize(deserialize(s)), s);
}

TEST(d003, equivalence_right) {
    std::string s{"v # r # rr # #"};

    ASSERT_EQ(serialize(deserialize(s)), s);
}

TEST(d003, equivalence_depth) {
    std::string s =
            "v l ll lll # # llr # # lr lrl # # lrr # # "
            "r rl rll # # rlr # # rr rrl # # rrr # #";

    ASSERT_EQ(serialize(deserialize(s)), s);
}
