//
// Created by yhzhan on 4/13/2020.
//

#include "gtest/gtest.h"
#include "common.h"
#include <chrono>
#include "contiguous_array.h"

using namespace contiguous_array;
TEST(contiguous_array, testcase) {
    EXPECT_EQ(Solution().findMaxLength({1,0}), 2);
    EXPECT_EQ(Solution().findMaxLength({1,0,1}), 2);
    EXPECT_EQ(Solution().findMaxLength({1,1,0,0}), 4);
}
