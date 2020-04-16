//
// Created by yhzhan on 4/16/2020.
//

#include "gtest/gtest.h"
#include "common.h"
#include "product_except_current.h"

using namespace product_except_current;
TEST(product_except_current, testcase) { // 12/2/2020 -> 737761
    EXPECT_EQ(Solution().productExceptSelf(std::vector<int>({1,2,3,4})),std::vector<int>({24,12,8,6}));
}
