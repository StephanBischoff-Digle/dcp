#include "gtest/gtest.h"
#include "solution.h"

TEST(d005, car) {
    auto pair = cons(3, 4);

    ASSERT_EQ(car(pair), 3);
}

TEST(d005, cdr) {
    auto pair = cons(3, 4);

    ASSERT_EQ(cdr(pair), 4);
}
