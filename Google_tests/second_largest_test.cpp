//
// Created by yhzhan on 3/16/2020.
//

#include "gtest/gtest.h"
#include "common.h"
#include <chrono>
#include "second_largest.h"
#include <unistd.h>


#define SLOW_FAST_COMP(val) \
    EXPECT_EQ(second_largest::fast::calculate(val), second_largest::slow::calculate(val))


TEST(second_largest_test, slow) {
    using namespace second_largest::slow;
    EXPECT_EQ(calculate(std::vector<int>{1,2,3,4,5,6,7,8}), 7);
    EXPECT_EQ(calculate(std::vector<int>{8,7,6,5,4,3,2,1}), 7);
}

TEST(second_largest_test, slow_fast) {
    SLOW_FAST_COMP((std::vector<int>{1,2,3,4,5,6,7,8}));
    SLOW_FAST_COMP((std::vector<int>{8,7,6,5,4,3,2,1}));
}
